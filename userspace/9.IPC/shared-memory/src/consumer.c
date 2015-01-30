#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "myshm.h"

int main(void)
{
	int shmid;
	void *shmem = NULL;
	struct test_struct *shst;
	int cont = 1;

	if((shmid = shmget((key_t)5555, sizeof(struct test_struct), IPC_CREAT)) == -1) {
		printf("Failed to create shared memory.\n");
		exit(EXIT_FAILURE);
	}

	if((shmem = shmat(shmid, (void *)0, 0)) == NULL) {
		printf("Failed to attach shared memory.\n");
                exit(EXIT_FAILURE);
	}

	shst = (struct test_struct *)shmem;

	while(cont) {
		if(shst->written) {
			printf("You have given: %s\n", shst->buffer);
			shst->written = 0;
			if((strncmp(shst->buffer, "done", 4)) == 0)
				cont = 0;
		}
	}

	exit(EXIT_SUCCESS);
}
