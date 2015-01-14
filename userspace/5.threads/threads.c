#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

#define NTHREADS 5

/* Function which is run by each thread upon creation */
void *thread_function(void *arg)
{
	char *message = (char *) arg;

	/* Print message passed from parent */
	printf("Message from user: %s\n", message);
	
	return NULL;
}

int main(void)
{
	char *msg[NTHREADS];
	int ret[NTHREADS], i = 0;
	pthread_t thread_id[NTHREADS];

	/* Allocate memory for char strings to store messages from user  */
	for(i = 0; i < NTHREADS; i++) {
                if((*(msg+i) = malloc(10)) == NULL) {
                        printf("Failed to allocate the memory.\n");
                        exit(EXIT_FAILURE);
                }
        }

	/* Take message from user for each thread  */
	for(i = 0; i < NTHREADS; i++) {
		printf("Enter message for thread %d:", i + 1);
                fgets(*(msg+i), 10, stdin);
        }

	printf("\n");

	/* Create new threads and pass one message to each thread  */
	for(i = 0; i < NTHREADS; i++) {
		ret[i] = pthread_create(&thread_id[i], NULL, thread_function, *(msg+i));	/* Thread creation */
		if(ret[i]) {
			/* Thread creation failed */
			fprintf(stderr,"Error - pthread_create() return code: %d\n",ret[i]);
         		exit(EXIT_FAILURE);
		}
	}

	for(i = 0; i < NTHREADS; i++) {
		pthread_join(thread_id[i], NULL);
	}

	return 0;
}
