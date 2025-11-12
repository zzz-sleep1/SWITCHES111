from __future__ import annotations

from collections import defaultdict
from dataclasses import dataclass
from pathlib import Path
from typing import Callable, Dict, List, Sequence, Tuple

import json
import random

# -----------------------------------------------------------------------------
# Configuration helpers
# -----------------------------------------------------------------------------

@dataclass
class SchedulerConfig:
    """Paths and knobs required by the Q-learning loop."""

    nsga_root: Path
    results_dir: Path
    generations_dir: Path
    objectives: Sequence[str]
    num_cores: int
    schedule_length: int
    max_steps_per_episode: int = 25
    initial_child_path: Path | None = None
    index_base: int = 0        # 0 = 0-based (MMULT), 1 = 1-based


DEFAULT_CONFIG = SchedulerConfig(
    nsga_root=Path(__file__).resolve().parent,
    results_dir=Path(__file__).resolve().parent / "Results",
    generations_dir=Path(__file__).resolve().parent / "Generations",
    objectives=("time",),
    num_cores=4,
    schedule_length=4,
    max_steps_per_episode=3,
    index_base=0,
)


# -----------------------------------------------------------------------------
# Bootstrap logic
# -----------------------------------------------------------------------------
def make_unique_permutation(vec: Sequence[int], num_cores: int) -> List[int]:
    """
    Normalize `vec` to a duplicate-free 0-based permutation:
    - Valid core range is [0, num_cores - 1]
    - Duplicate or out-of-range elements are replaced by yet-unused cores in order
    """
    lo, hi = 0, num_cores - 1
    pool = list(range(lo, hi + 1))
    used = set()
    out: List[int] = []

    for v in vec:
        if v in used or v < lo or v > hi:
            out.append(None)  # 占位，后面补
        else:
            out.append(v)
            used.add(v)

    remain = [c for c in pool if c not in used]
    ri = 0
    for k in range(len(out)):
        if out[k] is None:
            out[k] = remain[ri]
            ri += 1
    return out


def bootstrap_individual(config: SchedulerConfig) -> List[int]:
    if config.initial_child_path and config.initial_child_path.exists():
        with config.initial_child_path.open() as fp:
            raw = [int(line.strip()) for line in fp if line.strip()]
    else:
         # No seed: return the 0-based contiguous sequence 0..(L-1)
        raw = list(range(0, config.schedule_length))

    vec = make_unique_permutation(raw, config.num_cores)
    return vec[: config.schedule_length]




# -----------------------------------------------------------------------------
# Environment definition
# -----------------------------------------------------------------------------

Action = Tuple[int, int]  # swap task i and task j (i, j)
State = Tuple[int, ...]   # scheduling vector expressed as a tuple


def all_actions(num_tasks: int, num_cores: int) -> List[Action]:
    """Generate all swap(i, j) actions (i < j). Swapping preserves the duplicate-free property."""
    return [(i, j) for i in range(num_tasks) for j in range(i + 1, num_tasks)]


class SchedulingEnv:
    """Minimal environment for tabular Q-learning."""

    def __init__(
        self,
        config: SchedulerConfig,
        evaluate_fn: Callable[[Sequence[int], int, int], float],
    ) -> None:
        self.config = config
        self.evaluate_fn = evaluate_fn
        self.actions = all_actions(config.schedule_length, config.num_cores)
        self.state: State | None = None
        self.steps_taken = 0
        self.episode_index = 0
        self.eval_counter = 0

    # ------------------------------------------------------------------
    def reset(self, episode: int = 0) -> State:
        self.state = tuple(bootstrap_individual(self.config))
        self.steps_taken = 0
        self.episode_index = episode
        self.eval_counter = 0
        return self.state

    # ------------------------------------------------------------------
    def step(self, action_index: int) -> Tuple[State, float, bool, Dict[str, object]]:
        assert self.state is not None, "Call reset() before step()."

        i, j = self.actions[action_index]
        next_vector = list(self.state)
        next_vector[i], next_vector[j] = next_vector[j], next_vector[i]

        reward = self.evaluate_fn(next_vector, self.episode_index, self.eval_counter)
        self.eval_counter += 1

        self.state = tuple(next_vector)
        self.steps_taken += 1
        done = self.steps_taken >= self.config.max_steps_per_episode

        return self.state, reward, done, {"action": ("swap", i, j)}


# -----------------------------------------------------------------------------
# Evaluation hook
# -----------------------------------------------------------------------------
def evaluate_schedule_with_nsga_tools(
    schedule_vector: Sequence[int],
    config: SchedulerConfig,
    generation_id: int,
) -> float:
    """
    Write the schedule vector to Generations/Gen<id>/g<id>-c1 (0-based or 1-based is controlled
    by config.index_base), invoke the runner (5-argument form: app guest system GEN CHILD),
    read the average time from Results/Gen<id>/g<id>-c1-time.res, and return its negative as the reward.
    """
    import os
    import subprocess
    import statistics
    from datetime import datetime

    nsga_root = config.nsga_root

   # Read environment variables (use reasonable defaults if not set)
    runner = Path(os.environ.get("QLEARN_RUNNER", nsga_root / "run_single_schedule.sh"))
    app = Path(os.environ.get("QLEARN_APP", "mmult.c"))  
    guest = os.environ.get("QLEARN_GUEST", "localhost")
    system = os.environ.get("QLEARN_SYSTEM", "multicore")
    repeats_env = os.environ.get("REPEATS", None)  

    # Basic existence check
    if not runner.exists():
        raise FileNotFoundError(f"runner not found: {runner}")

    # Prepare directories
    gen_dir = config.generations_dir / f"Gen{generation_id}"
    res_dir = config.results_dir / f"Gen{generation_id}"
    gen_dir.mkdir(parents=True, exist_ok=True)
    res_dir.mkdir(parents=True, exist_ok=True)

    child_id = 1
    sched_path = gen_dir / f"g{generation_id}-c{child_id}"

    def _assert_no_dup_and_in_range(vec: Sequence[int], num_cores: int) -> None:
        lo, hi = 0, num_cores - 1  # 0-based
        assert len(set(vec)) == len(vec), f"Duplicate cores in schedule: {vec}"
        assert all(lo <= v <= hi for v in vec), f"Core id out of range [{lo},{hi}] in {vec}"

     # Write schedule file 
    _assert_no_dup_and_in_range(schedule_vector, config.num_cores)
    with (config.generations_dir / f"Gen{generation_id}" / f"g{generation_id}-c1").open("w") as fp:
        for v in schedule_vector:
            fp.write(f"{int(v)}\n")


    # Build the runner command: 5 arguments (use the app's filename to avoid absolute-path issues with APP_BIN)
    cmd = [
        str(runner),
        app.name,
        str(guest),
        str(system),
        str(generation_id),
        str(child_id),
    ]
    env = os.environ.copy()
    if repeats_env is not None:
        env["REPEATS"] = repeats_env  # runner reads REPEATS to control number of repetitions

    if not os.access(runner, os.X_OK):
        cmd = ["bash"] + cmd

    # Log to help with debugging
    log_file = res_dir / f"g{generation_id}-c{child_id}.log"
    with log_file.open("wb") as lg:
        lg.write(f"[{datetime.now().isoformat()}] CMD: {' '.join(cmd)}\n".encode())
        subprocess.run(cmd, cwd=nsga_root, check=True, stdout=lg, stderr=lg, env=env)

    # Read timing results: prefer .res; if missing, parse __aid_Time: from .out
    time_res = res_dir / f"g{generation_id}-c{child_id}-time.res"
    time_out = res_dir / f"g{generation_id}-c{child_id}-time.out"

    runtime_value: float | None = None
    if time_res.exists():
        try:
            runtime_value = float(time_res.read_text().strip())
        except Exception:
            runtime_value = None

    if runtime_value is None and time_out.exists():
        try:
            vals: list[float] = []
            token = "__aid_Time:"
            for line in time_out.read_text().splitlines():
                parts = line.split()
                for i, w in enumerate(parts[:-1]):
                    if w == token:
                        try:
                            vals.append(float(parts[i + 1]))
                        except ValueError:
                            pass
            if vals:
                runtime_value = statistics.fmean(vals)
        except Exception:
            runtime_value = None



    # Smaller time is better → return the negative runtime as reward
    return -float(runtime_value)




# -----------------------------------------------------------------------------
# Q-learning agent
# -----------------------------------------------------------------------------

class QLearningAgent:
    def __init__(
        self,
        actions: Sequence[Action],
        alpha: float = 0.1,
        gamma: float = 0.9,
        epsilon: float = 0.2,
        epsilon_min: float = 0.05,
        epsilon_decay: float = 0.99,
    ) -> None:
        self.actions = actions
        self.alpha = alpha
        self.gamma = gamma
        self.epsilon = epsilon
        self.epsilon_min = epsilon_min
        self.epsilon_decay = epsilon_decay
        self.q_table: Dict[State, List[float]] = defaultdict(lambda: [0.0] * len(actions))

    # ------------------------------------------------------------------
    def choose_action(self, state: State) -> int:
        if random.random() < self.epsilon:
            return random.randrange(len(self.actions))
        return int(max(range(len(self.actions)), key=lambda idx: self.q_table[state][idx]))

    # ------------------------------------------------------------------
    def update(self, state: State, action_idx: int, reward: float, next_state: State) -> None:
        best_next = max(self.q_table[next_state])
        current = self.q_table[state][action_idx]
        self.q_table[state][action_idx] = current + self.alpha * (reward + self.gamma * best_next - current)

    # ------------------------------------------------------------------
    def anneal(self) -> None:
        self.epsilon = max(self.epsilon_min, self.epsilon * self.epsilon_decay)


# -----------------------------------------------------------------------------
# Training loop
# -----------------------------------------------------------------------------

def q_learning_train(
    env: SchedulingEnv,
    agent: QLearningAgent,
    episodes: int,
    config: SchedulerConfig,
) -> Tuple[State, float]:
    """Main Q-learning driver. Returns the best state and its reward."""

    best_state: State | None = None
    best_reward = float("-inf")

    for episode in range(episodes):
        state = env.reset(episode)
        done = False

        while not done:
            action_idx = agent.choose_action(state)
            next_state, reward, done, _ = env.step(action_idx)

            agent.update(state, action_idx, reward, next_state)
            state = next_state

            # Track the best performing schedule.
            if reward > best_reward:
                best_state = state
                best_reward = reward

        agent.anneal()

        # Optional: persist debug info per episode.
        debug_payload = {
            "episode": episode,
            "reward": best_reward,
            "epsilon": agent.epsilon,
        }
        (config.results_dir / "debug").mkdir(parents=True, exist_ok=True)
        with (config.results_dir / "debug" / f"episode_{episode}.json").open("w") as fp:
            json.dump(debug_payload, fp, indent=2)

    assert best_state is not None, "Training did not evaluate any state."
    return best_state, best_reward


# -----------------------------------------------------------------------------
# Utilities
# -----------------------------------------------------------------------------

def save_final_schedule(schedule: Sequence[int], config: SchedulerConfig) -> Path:
    """Store the best schedule in the Results directory for downstream tools."""

    config.results_dir.mkdir(parents=True, exist_ok=True)
    final_path = config.results_dir / "final_schedule.sch"
    with final_path.open("w") as fp:
        for core_id in schedule:
            fp.write(f"{core_id}\n")
    return final_path


# -----------------------------------------------------------------------------
# Script entry point
# -----------------------------------------------------------------------------

def main() -> None:
    config = DEFAULT_CONFIG

    # Ensure the NSGA helper folders exist.
    config.generations_dir.mkdir(parents=True, exist_ok=True)
    config.results_dir.mkdir(parents=True, exist_ok=True)

    def evaluate_callback(schedule_vector: Sequence[int], episode: int, eval_index: int) -> float:
        GEN_OFFSET = 1  # 让训练从 Gen1 开始
        generation_id = episode * config.max_steps_per_episode + eval_index + GEN_OFFSET
        return evaluate_schedule_with_nsga_tools(schedule_vector, config, generation_id=generation_id)

    env = SchedulingEnv(config=config, evaluate_fn=evaluate_callback)
    agent = QLearningAgent(actions=env.actions)

    best_state, best_reward = q_learning_train(
        env=env,
        agent=agent,
        episodes=10,
        config=config,
    )

    final_path = save_final_schedule(best_state, config)
    print(f"Best schedule stored in {final_path} with reward {best_reward:.3f}")


if __name__ == "__main__":
    main()
