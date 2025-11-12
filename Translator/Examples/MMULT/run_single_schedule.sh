#!/bin/bash
# Lightweight single-schedule translator & time evaluator
# Keeps paths/names consistent with run_nsga.sh
# Usage:
#   ./run_single_schedule.sh <application.c> <guest> <system> <generation> <child> [<schedule_file>] [repeats]
# Example:
#   ./run_single_schedule.sh test.c mic0 phi 1 3 Generations/Gen1/g1-c3 5

set -euo pipefail

# ---------- Global defaults (match originals where applicable) ----------
AFFINITY=compact
REPEATS_DEFAULT=3

# ---------- Args ----------
if [ "$#" -lt 5 ] || [ "$#" -gt 7 ]; then
  echo "ERROR: Illegal number of parameters."
  echo "Usage:"
  echo "  $0 <application.c> <guest> <system> <generation> <child> [<schedule_file>] [repeats]"
  exit 1
fi

APP=$1
GUEST=$2          # kept for interface compatibility (unused here)
SYSTEM=$3
GEN=$4
CHILD=$5
SCHED_SRC="${6:-}"                   # optional: a schedule file to copy in place
REPEATS="${7:-$REPEATS_DEFAULT}"

# ---------- Checks ----------
if [[ ! -f "$APP" ]]; then
  echo "ERROR: File [ $APP ] doesn't exist!"
  exit 1
fi

APP_BIN=sw_${APP::-2}

# Thread mapping kept the same spirit as original script
THREADS=""
if [ "$SYSTEM" = "phi" ]; then THREADS=240; fi
if [ "$SYSTEM" = "amd" ]; then THREADS=12; fi
if [ "$SYSTEM" = "office" ] || [ "$SYSTEM" = "multicore" ]; then THREADS=4; fi
if [ -z "${THREADS}" ]; then
  echo "WARNING: Unrecognized system '$SYSTEM'. Defaulting THREADS=4 to proceed."
  THREADS=4
fi

# ---------- Prepare paths (same layout/names as original) ----------
mkdir -p "Generations/Gen${GEN}"
mkdir -p "Results/Gen${GEN}"

SCHED_PATH="Generations/Gen${GEN}/g${GEN}-c${CHILD}"

# If user provided a schedule file, place/copy it to the canonical location
if [ -n "$SCHED_SRC" ]; then
  cp "$SCHED_SRC" "$SCHED_PATH"
fi

if [[ ! -f "$SCHED_PATH" ]]; then
  echo "ERROR: Schedule file not found at [$SCHED_PATH]."
  echo "Provide it as arg 6, or create it at that path."
  exit 1
fi

# ---------- Translate & build ----------
echo -n "Translating child (Gen=${GEN}, Child=${CHILD})... "
make -f Makefile clean > /dev/null
switches -s "$SYSTEM" "$THREADS" "$THREADS" -i "$APP" -t "$THREADS" -sched file "$SCHED_PATH" -a "$AFFINITY"
make -f Makefile > /dev/null
echo "DONE"

# ---------- Run & collect time objective only ----------
OUT_DIR="Results/Gen${GEN}"
TIME_OUT="${OUT_DIR}/g${GEN}-c${CHILD}-time.out"
TIME_TMP="${OUT_DIR}/g${GEN}-c${CHILD}-time.tmp"
TIME_RES="${OUT_DIR}/g${GEN}-c${CHILD}-time.res"

: > "$TIME_OUT"

PWD_NOW="$(pwd)"
CV_REPEATS=0
echo -n "Executing $REPEATS run(s) for timing... "
while [ $CV_REPEATS -lt $REPEATS ]; do
  cd "$PWD_NOW"
  ./"$APP_BIN" >> "$TIME_OUT"
  CV_REPEATS=$((CV_REPEATS+1))
done
echo "DONE"

# ---------- Average time exactly like the original script ----------
# Parse numbers that follow the token "__aid_Time:"
flag=0
AVERAGE="0.0"
while IFS= read -r line; do
  for word in $line; do
    if [ "$flag" = "1" ]; then
      AVERAGE=$(echo "$AVERAGE + $word" | bc -l)
      flag=0
    fi
    if [ "$word" = "__aid_Time:" ]; then
      flag=1
    fi
  done
done < "$TIME_OUT"

AVERAGE=$(echo "$AVERAGE / $REPEATS" | bc -l)
echo "$AVERAGE" > "$TIME_TMP"
mv "$TIME_TMP" "$TIME_RES"

echo "Average time written to: $TIME_RES"
