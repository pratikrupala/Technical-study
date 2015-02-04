#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <semaphore.h>

#define NTHREADS 10	//Number of threads this program will generate
#define INDEX 5

/* Global variables which will be accessed by more than one thread */
int var[INDEX];

/* Semaphore to protect global variable var*/
sem_t mysem;

/* This is the common function used by all threads.
 * This function once increament and once decrement the global variable var.
 * As proper locking is provided by semaphore, variable var should be unchanged at the end of the function.
 */
void *my_thread(void *arg)
{
	int n = 10000, i = 0, m = 0;
	sem_wait(&mysem);
	int *idx;
	idx = (int *)arg;
	m = var[*idx];
	m++;
	var[*idx] = m;
	for(i = 0; i < n; i++);
	m = var[*idx];
	m--;
	var[*idx] = m;
	sem_post(&mysem);
	pthread_exit(NULL);
}

int main(void)
{
	int i = 0, ret[NTHREADS], r = 0;
	int count[NTHREADS];
	pthread_t thread_id[NTHREADS];

	/* Take input from user for global array. */
	for(i = 0; i < INDEX; i++) {
		printf("Enter the value for index %d in global variable:", i);
		scanf("%d", &var[i]);
	}

	for(i = 0; i < NTHREADS; i++) {
		if(i < INDEX)
			count[i] = i;
		else
			count[i] = (i - INDEX);
	}

	/* Initialize semaphore */
        r = sem_init(&mysem, 0, NTHREADS);
        if(r != 0) {
                fprintf(stderr, "Error - sem_init() return code: %d\n", r);
                exit(EXIT_FAILURE);
        }

	for(i = 0; i < NTHREADS; i++) {
		ret[i] = pthread_create(&thread_id[i], NULL, my_thread, &count[i]);
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
	for(i = 0; i < INDEX; i++) {
		printf("Value of var at the end at index %d: %d\n", i, var[i]);
	}

	/* Destroy the semaphore after used. */
        sem_destroy(&mysem);

	exit(EXIT_SUCCESS);
}
