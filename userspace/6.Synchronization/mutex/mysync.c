#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <semaphore.h>

#define NTHREADS 10000

/* Global variable which will be accessed by more than one thread */
int var;
/* Mutex to protect global variable */
pthread_mutex_t mymutex;

/* This is the common function used by all threads.
 * This function once increament and once decrement the global variable var.
 * As proper locking is provided by mutex, variable var should be unchanged at the end of the function. */
void *my_thread(void *arg)
{
	int n = 10000, i = 0, m = 0;
	pthread_mutex_lock(&mymutex);
	m = var;
	m++;
	var = m;
	for(i = 0; i < n; i++);
	m = var;
	m--;
	var = m;
	pthread_mutex_unlock(&mymutex);
	pthread_exit(NULL);
}

int main(void)
{
	int i = 0, ret[NTHREADS], r = 0;
	pthread_t thread_id[NTHREADS];

	printf("Enter the value of global variable:");
	scanf("%d", &var);

	/* Initialize the mutex */
	r = pthread_mutex_init(&mymutex, NULL);
	if(r != 0) {
		fprintf(stderr, "Error - pthread_mutex_init() return code: %d\n", r);
		exit(EXIT_FAILURE);
	}

	for(i = 0; i < NTHREADS; i++) {
		ret[i] = pthread_create(&thread_id[i], NULL, my_thread, NULL);
		if(ret[i]) {
			fprintf(stderr, "Error - pthread_create() return code: %d\n", ret[i]);
			exit(EXIT_FAILURE);
		}
	}

	for(i = 0; i < NTHREADS; i++) {
		pthread_join(thread_id[i], NULL);
	}

	/* As proper locking mechanism is used, this var will be same as given by user */
	printf("Value of var at the end:%d\n", var);

	/* Destroy the mutex after used. */
	pthread_mutex_destroy(&mymutex);

	exit(EXIT_SUCCESS);
}
