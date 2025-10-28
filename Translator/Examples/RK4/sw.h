#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>
#include <sched.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>


/************************** General Definitions *****************************/

#define __KERNELS  4
#define __PTHREADS (__KERNELS-1)
#define __ON       1
#define __OFF      0
#define TRUE       1
#define FALSE      0


/************************** Error Printing Colors *****************************/

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_WHITE   "\x1B[37m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define ERROR(FormalLiteral, ...)   fprintf(stderr, ANSI_COLOR_RED "%s:%d: ERROR: " FormalLiteral ANSI_COLOR_RESET "\n", __FILE__, __LINE__, __VA_ARGS__);



/************************ Declare all the KERNELS here ************************/

#define __MAIN_KERNEL 0
#define __KERNEL_1    1
#define __KERNEL_2    2
#define __KERNEL_3    3


/********************** Threadpool Function Prototypes ************************/

pthread_t __kernels[__PTHREADS];
pthread_barrier_t barrier[5];                   // # of functions + 1 (for the entire thread_jobs)

void __threadpool_initialize(int);
void __threadpool_destroy();


/******************** Thread Complex Arguments Definition **********************/

typedef struct __arguments{

    long   id;
    long   function_id;

}__arguments;


/************************** Declare Loop Chunk Sizes **************************/

#define __LOOP_1_CHUNK    32
#define __LOOP_2_CHUNK    32
#define __LOOP_3_CHUNK    32
#define __LOOP_4_CHUNK    32


/************************** Declare Loop Kernel Number **************************/

#define __LOOP_1_KERNELS    4
#define __LOOP_2_KERNELS    4
#define __LOOP_3_KERNELS    4
#define __LOOP_4_KERNELS    4


/************************** Declare Loop Counters **************************/

#define __LOOP_1_COUNTER    (__LOOP_1_CHUNK * __LOOP_1_KERNELS)
#define __LOOP_2_COUNTER    (__LOOP_2_CHUNK * __LOOP_2_KERNELS)
#define __LOOP_3_COUNTER    (__LOOP_3_CHUNK * __LOOP_3_KERNELS)
#define __LOOP_4_COUNTER    (__LOOP_4_CHUNK * __LOOP_4_KERNELS)


/************************** Declare Parallel Functions **************************/

#define __FUNCTION_1    1
#define __FUNCTION_2    2
#define __FUNCTION_3    3
#define __FUNCTION_4    4


/*********************** Functions Prototypes ************************/

void __sw_resetSWitches_1(int);
void __sw_resetSWitches_2(int);
void __sw_resetSWitches_3(int);
void __sw_resetSWitches_4(int);
void *thread_jobs(void *);
void *parallel_function_1(void *);
void *parallel_function_2(void *);
void *parallel_function_3(void *);
void *parallel_function_4(void *);


