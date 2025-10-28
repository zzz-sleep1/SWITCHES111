#include "sw.h"



/*** APPLICATION Definitions & Includes ****/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#define SIZE 9600


/*** APPLICATION declarations ****/

extern double *yt;
extern double *k1;
extern double *k2;
extern double *k3;
extern double *k4;
extern double *yout;
extern double totalSum;
extern double*  y;
extern double*  power;
extern double** c;
extern double h;
extern double sum;
extern int i,j;

long currentFunction = 0;



/*** Declare all the SWITCHES here ***/

bool __sw_task_1[4]    = {__OFF};
bool __sw_task_2[4]    = {__OFF};
bool __sw_task_3[4]    = {__OFF};
bool __sw_task_4[4]    = {__OFF};


/*** Declare Task Counter of each Thread & per Function ***/

long __sw_taskCounter_Function_1[__KERNELS]  = { 1, 1, 1, 1 };
long __sw_taskCounter_Function_2[__KERNELS]  = { 1, 1, 1, 1 };
long __sw_taskCounter_Function_3[__KERNELS]  = { 1, 1, 1, 1 };
long __sw_taskCounter_Function_4[__KERNELS]  = { 1, 1, 1, 1 };



	/*** Reset Switches Functions ***/

/* Reset the switches of Parallel Function 1 */

void __sw_resetSWitches_1(int tid)
{

    switch(tid)
    {
         case __MAIN_KERNEL:
            __sw_task_1[0] = __OFF;
            break;

         case __KERNEL_1:
            __sw_task_1[1] = __OFF;
            break;

         case __KERNEL_2:
            __sw_task_1[2] = __OFF;
            break;

         case __KERNEL_3:
            __sw_task_1[3] = __OFF;
            break;

    }

}

/* Reset the switches of Parallel Function 2 */

void __sw_resetSWitches_2(int tid)
{

    switch(tid)
    {
         case __MAIN_KERNEL:
            __sw_task_2[0] = __OFF;
            break;

         case __KERNEL_1:
            __sw_task_2[1] = __OFF;
            break;

         case __KERNEL_2:
            __sw_task_2[2] = __OFF;
            break;

         case __KERNEL_3:
            __sw_task_2[3] = __OFF;
            break;

    }

}

/* Reset the switches of Parallel Function 3 */

void __sw_resetSWitches_3(int tid)
{

    switch(tid)
    {
         case __MAIN_KERNEL:
            __sw_task_3[0] = __OFF;
            break;

         case __KERNEL_1:
            __sw_task_3[1] = __OFF;
            break;

         case __KERNEL_2:
            __sw_task_3[2] = __OFF;
            break;

         case __KERNEL_3:
            __sw_task_3[3] = __OFF;
            break;

    }

}

/* Reset the switches of Parallel Function 4 */

void __sw_resetSWitches_4(int tid)
{

    switch(tid)
    {
         case __MAIN_KERNEL:
            __sw_task_4[0] = __OFF;
            break;

         case __KERNEL_1:
            __sw_task_4[1] = __OFF;
            break;

         case __KERNEL_2:
            __sw_task_4[2] = __OFF;
            break;

         case __KERNEL_3:
            __sw_task_4[3] = __OFF;
            break;

    }

}


/*** Jobs Thread Function ***/

void *thread_jobs(void *arg)
{
    long tid;
    long myFunction = 0;
    // Thread Affinity variables
    int __affinity_out = 0;
    cpu_set_t cpuset;
    __arguments *arguments;
    arguments = (__arguments*) arg;

    tid = arguments->id;
    myFunction = arguments->function_id;

    // Activate Thread Affinity
    CPU_ZERO(&cpuset);
    CPU_SET(tid+1, &cpuset);
    __affinity_out = pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);

    if(tid == __MAIN_KERNEL){
        currentFunction = myFunction;
        __sync_synchronize();
     }


    do{

        pthread_barrier_wait(&barrier[0]);
        myFunction = currentFunction;
        __sync_synchronize();

        switch(myFunction){

            case __FUNCTION_1:
                parallel_function_1((void *)tid);
                pthread_barrier_wait(&barrier[__FUNCTION_1]);
                __sw_resetSWitches_1(tid);
                break;

            case __FUNCTION_2:
                parallel_function_2((void *)tid);
                pthread_barrier_wait(&barrier[__FUNCTION_2]);
                __sw_resetSWitches_2(tid);
                break;

            case __FUNCTION_3:
                parallel_function_3((void *)tid);
                pthread_barrier_wait(&barrier[__FUNCTION_3]);
                __sw_resetSWitches_3(tid);
                break;

            case __FUNCTION_4:
                parallel_function_4((void *)tid);
                pthread_barrier_wait(&barrier[__FUNCTION_4]);
                __sw_resetSWitches_4(tid);
                break;

        }

        if(tid == __MAIN_KERNEL)
            break;

    }while(myFunction != -1);



    if(tid != __MAIN_KERNEL)
        pthread_exit(NULL);

}


/*** Application Parallel Function ***/


/*** Reduction Global Variables ***/



void *parallel_function_1(void *arg)
{
    long tid;
    long vTid = 0;
    tid = (long)arg;
    bool ready = FALSE;
    long __sw_tasksCounter = __sw_taskCounter_Function_1[tid];

    /*** Declare private/firstprivate variables ***/

    int i = 0;
    int j = 0;
    // Loop task private variables
    long __sw_i               = 0;
    long __sw_loop_start      = 0;
    long __sw_loop_end        = 0;
    long __sw_loop_chunk      = 0;

    do{

        /******************* TASK [ 1 ] *******************/

        switch(tid){
            case __MAIN_KERNEL: vTid = 0; if(ready = (!__sw_task_1[vTid])) break;
                              break;
            case __KERNEL_1: vTid = 1; if(ready = (!__sw_task_1[vTid])) break;
                              break;
            case __KERNEL_2: vTid = 2; if(ready = (!__sw_task_1[vTid])) break;
                              break;
            case __KERNEL_3: vTid = 3; if(ready = (!__sw_task_1[vTid])) break;
                              break;
            default:  ready = FALSE; break;
        }

    if(ready){

        ready = FALSE;

            __sw_loop_start   =  0 + vTid * __LOOP_1_CHUNK;
            __sw_loop_end     =  SIZE;

            for (__sw_i = __sw_loop_start; __sw_i < __sw_loop_end; __sw_i += __LOOP_1_COUNTER){

                __sw_loop_chunk = __sw_i + (((__sw_loop_end - __sw_i) >= __LOOP_1_CHUNK) ? __LOOP_1_CHUNK : (__sw_loop_end - __sw_i));

			    for (i = __sw_i;  i < __sw_loop_chunk;  i++) 
		{ 
			yt[i] = 0.0;
			for (j = 0; j < SIZE; j++) 
				yt[i] += c[i][j]*y[j];
			k1[i] = h*(power[i]-yt[i]);
		}
	            }


        // Update your switch && sync with main memory
        __sw_task_1[vTid] = __ON;
        __sw_tasksCounter--;

        __sync_synchronize();

    }
       if(!__sw_tasksCounter) break;


    }while(__sw_tasksCounter);

}


/*** Application Parallel Function ***/


/*** Reduction Global Variables ***/



void *parallel_function_2(void *arg)
{
    long tid;
    long vTid = 0;
    tid = (long)arg;
    bool ready = FALSE;
    long __sw_tasksCounter = __sw_taskCounter_Function_2[tid];

    /*** Declare private/firstprivate variables ***/

    int i = 0;
    int j = 0;
    // Loop task private variables
    long __sw_i               = 0;
    long __sw_loop_start      = 0;
    long __sw_loop_end        = 0;
    long __sw_loop_chunk      = 0;

    do{

        /******************* TASK [ 2 ] *******************/

        switch(tid){
            case __MAIN_KERNEL: vTid = 0; if(ready = (!__sw_task_2[vTid])) break;
                              break;
            case __KERNEL_1: vTid = 1; if(ready = (!__sw_task_2[vTid])) break;
                              break;
            case __KERNEL_2: vTid = 2; if(ready = (!__sw_task_2[vTid])) break;
                              break;
            case __KERNEL_3: vTid = 3; if(ready = (!__sw_task_2[vTid])) break;
                              break;
            default:  ready = FALSE; break;
        }

    if(ready){

        ready = FALSE;

            __sw_loop_start   =  0 + vTid * __LOOP_2_CHUNK;
            __sw_loop_end     =  SIZE;

            for (__sw_i = __sw_loop_start; __sw_i < __sw_loop_end; __sw_i += __LOOP_2_COUNTER){

                __sw_loop_chunk = __sw_i + (((__sw_loop_end - __sw_i) >= __LOOP_2_CHUNK) ? __LOOP_2_CHUNK : (__sw_loop_end - __sw_i));

			    for (i = __sw_i;  i < __sw_loop_chunk;  i++) 
		{
			yt[i] = 0.0;
			for (j = 0; j < SIZE; j++) 
				yt[i] += c[i][j]*(y[j]+0.5*k1[j]);
			k2[i] = h*(power[i]-yt[i]);
		}
	            }


        // Update your switch && sync with main memory
        __sw_task_2[vTid] = __ON;
        __sw_tasksCounter--;

        __sync_synchronize();

    }
       if(!__sw_tasksCounter) break;


    }while(__sw_tasksCounter);

}


/*** Application Parallel Function ***/


/*** Reduction Global Variables ***/



void *parallel_function_3(void *arg)
{
    long tid;
    long vTid = 0;
    tid = (long)arg;
    bool ready = FALSE;
    long __sw_tasksCounter = __sw_taskCounter_Function_3[tid];

    /*** Declare private/firstprivate variables ***/

    int i = 0;
    int j = 0;
    // Loop task private variables
    long __sw_i               = 0;
    long __sw_loop_start      = 0;
    long __sw_loop_end        = 0;
    long __sw_loop_chunk      = 0;

    do{

        /******************* TASK [ 3 ] *******************/

        switch(tid){
            case __MAIN_KERNEL: vTid = 0; if(ready = (!__sw_task_3[vTid])) break;
                              break;
            case __KERNEL_1: vTid = 1; if(ready = (!__sw_task_3[vTid])) break;
                              break;
            case __KERNEL_2: vTid = 2; if(ready = (!__sw_task_3[vTid])) break;
                              break;
            case __KERNEL_3: vTid = 3; if(ready = (!__sw_task_3[vTid])) break;
                              break;
            default:  ready = FALSE; break;
        }

    if(ready){

        ready = FALSE;

            __sw_loop_start   =  0 + vTid * __LOOP_3_CHUNK;
            __sw_loop_end     =  SIZE;

            for (__sw_i = __sw_loop_start; __sw_i < __sw_loop_end; __sw_i += __LOOP_3_COUNTER){

                __sw_loop_chunk = __sw_i + (((__sw_loop_end - __sw_i) >= __LOOP_3_CHUNK) ? __LOOP_3_CHUNK : (__sw_loop_end - __sw_i));

			    for (i = __sw_i;  i < __sw_loop_chunk;  i++) 
		{
			yt[i] = 0.0;
			for (j = 0; j < SIZE; j++) 
				yt[i] += c[i][j]*(y[j]+0.5*k2[j]);
			k3[i] = h*(power[i]-yt[i]);
		}
	            }


        // Update your switch && sync with main memory
        __sw_task_3[vTid] = __ON;
        __sw_tasksCounter--;

        __sync_synchronize();

    }
       if(!__sw_tasksCounter) break;


    }while(__sw_tasksCounter);

}


/*** Application Parallel Function ***/


/*** Reduction Global Variables ***/

double __sw_sum_task_4[4]          = {0};


void *parallel_function_4(void *arg)
{
    long tid;
    long vTid = 0;
    tid = (long)arg;
    bool ready = FALSE;
    long __sw_tasksCounter = __sw_taskCounter_Function_4[tid];

    /*** Declare private/firstprivate variables ***/

    int i = 0;
    int j = 0;
    // Loop task private variables
    long __sw_i               = 0;
    long __sw_loop_start      = 0;
    long __sw_loop_end        = 0;
    long __sw_loop_chunk      = 0;
    // Reduction task private variables
    double sum = 0;

    do{

        /******************* TASK [ 4 ] *******************/

        switch(tid){
            case __MAIN_KERNEL: vTid = 0; if(ready = (!__sw_task_4[vTid])) break;
                              break;
            case __KERNEL_1: vTid = 1; if(ready = (!__sw_task_4[vTid])) break;
                              break;
            case __KERNEL_2: vTid = 2; if(ready = (!__sw_task_4[vTid])) break;
                              break;
            case __KERNEL_3: vTid = 3; if(ready = (!__sw_task_4[vTid])) break;
                              break;
            default:  ready = FALSE; break;
        }

    if(ready){

        ready = FALSE;

            __sw_loop_start   = 0 + vTid * __LOOP_4_CHUNK;
            __sw_loop_end     =  SIZE;
            // Re-initialize Reduction variables
             sum = 0;

            for (__sw_i = __sw_loop_start; __sw_i < __sw_loop_end; __sw_i += __LOOP_4_COUNTER){

                __sw_loop_chunk = __sw_i + (((__sw_loop_end - __sw_i) >= __LOOP_4_CHUNK) ? __LOOP_4_CHUNK : (__sw_loop_end - __sw_i));

			    for (i = __sw_i;  i < __sw_loop_chunk;  i++) 
		{
			yt[i]=0.0;
			for (j = 0; j < SIZE; j++) 
				yt[i] += c[i][j]*(y[j]+k3[j]);
			k4[i] = h*(power[i]-yt[i]);

			yout[i] = y[i] + (k1[i] + 2*k2[i] + 2*k3[i] + k4[i])/6.0;
			sum+=yout[i];
		}
	            }

            __sw_sum_task_4[vTid] = sum;

        // Update your switch && sync with main memory
        __sw_task_4[vTid] = __ON;
        __sw_tasksCounter--;

        __sync_synchronize();
        if(tid == __MAIN_KERNEL){

            if(!__sw_task_4[0]){
            __sync_synchronize();
            continue;
            }

            while(!__sw_task_4[0] || !__sw_task_4[1] || !__sw_task_4[2] || !__sw_task_4[3]){
            __sync_synchronize();
            }

               extern double sum;
               sum = sum + __sw_sum_task_4[0] + __sw_sum_task_4[1] + __sw_sum_task_4[2] + __sw_sum_task_4[3];
        }


    }
       if(!__sw_tasksCounter) break;


    }while(__sw_tasksCounter);

}

