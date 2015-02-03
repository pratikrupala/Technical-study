#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <semaphore.h>

#define NTHREADS 10000	//Number of threads this program will generate

/* Global variable which will be accessed by more than one thread */
int var;

/* This is the common function used by all threads.
 * This function once increament and once decrement the global variable var.
 * If it works properly then value of global variable var should be unchanged at the end of the function.
 * But in the absence of proper locking, some ambiguous value resides in var at the end. */
void *my_thread(void *arg)
{
	int n = 10000, i = 0, m = 0;
	m = var;
	m++;
	var = m;
	for(i = 0; i < n; i++);
	m = var;
	m--;
	var = m;
	pthread_exit(NULL);
}

int main(void)
{
	int i = 0, ret[NTHREADS], r = 0;
	pthread_t thread_id[NTHREADS];

	/* Take input from user for global variable. */
	printf("Enter the value of global variable:");
	scanf("%d", &var);

	for(i = 0; i < NTHREADS; i++) {
		ret[i] = pthread_create(&thread_id[i], NULL, my_thread, NULL);
		if(ret[i]) { /* Failed to create thread */
			fprintf(stderr, "Error - pthread_create() return code: %d\n", ret[i]);
			exit(EXIT_FAILURE);
		}
	}

	for(i = 0; i < NTHREADS; i++) {
		r = pthread_join(thread_id[i], NULL);
		if(r != 0) {
			fprintf(stderr, "Error - pthread_join() return code: %d\n", r);
			exit(EXIT_FAILURE);
		}
	}

	/* If all threads work properly, this print statement should print value of var same as it was given by user.
	 * But in the absence of proper locking, it prints some other value. */
	printf("Value of var at the end:%d\n", var);

	exit(EXIT_SUCCESS);
}
