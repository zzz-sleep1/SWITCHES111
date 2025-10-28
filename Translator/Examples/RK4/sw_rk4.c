#include "sw.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>


#define SIZE 9600

struct timeval startTime;
struct timeval finishTime;
double timeIntervalLength;


double *yt;
double *k1;
double *k2;
double *k3;
double *k4;
double *yout;
double totalSum;

double*  y;
double*  power;
double** c;

double h;
double sum;

int i,j;

void* myMalloc(int size, int info)
{
	void* t = (void*)malloc(size);

	if(!t)
	{
		printf("\nMemory allocation error [%d]",info);
		fflush(stdout);
		exit(0);
	}
	
	return t;
}

int main(int argc, char* argv[])
{
	
	h=0.3154;
	sum=0;

	//
	//MEMORY ALLOCATION
	//
	y    = (double* )myMalloc(SIZE*sizeof(double) ,1);
	power  = (double* )myMalloc(SIZE*sizeof(double) ,2);
	c    = (double**)myMalloc(SIZE*sizeof(double*),3);
	for (i=0;i<SIZE;i++) 
	{
		c[i]=(double*)myMalloc(SIZE*sizeof(double),4);
	}
	
	yt    = (double*)myMalloc(SIZE*sizeof(double*),4);
	k1    = (double*)myMalloc(SIZE*sizeof(double*),5);
	k2    = (double*)myMalloc(SIZE*sizeof(double*),6);
	k3    = (double*)myMalloc(SIZE*sizeof(double*),7);
	k4    = (double*)myMalloc(SIZE*sizeof(double*),8);
	yout  = (double*)myMalloc(SIZE*sizeof(double*),9);

	

	
	//
	//INITIALIZATION
	//
	for (i = 0; i < SIZE; i++) 
	{
		y[i]=i*i;
		power[i]=i+i;
		for (j = 0; j < SIZE; j++)
		{
			c[i][j]=i*i+j;
		}
	}

	

	// Start timers
	gettimeofday(&startTime, NULL);


	__threadpool_initialize(__FUNCTION_1);


	
	__threadpool_initialize(__FUNCTION_2);




	__threadpool_initialize(__FUNCTION_3);




	__threadpool_initialize(__FUNCTION_4);


	
	// End timers
 	gettimeofday(&finishTime, NULL);


	//Calculate the interval length 
	timeIntervalLength = (double)(finishTime.tv_sec-startTime.tv_sec) * 1000000 
	                     + (double)(finishTime.tv_usec-startTime.tv_usec);
	timeIntervalLength=timeIntervalLength/1000;

	//Print the interval lenght
	printf("__aid_Time: %g msec.\n", timeIntervalLength);
	

	printf("\n\nTotalSum=%g\n\n",sum);
	fflush(stdout);

	

	

   /* Parallel sections is finished -- Destroy threadpool */
   __threadpool_initialize(-1);
   __threadpool_destroy();
   pthread_exit(NULL);

return 0;
}
