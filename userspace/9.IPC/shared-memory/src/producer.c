#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "myshm.h"

int main(void)
{
	int shmid;
	void *shmem = NULL;
	char str[BUF_SIZE + 1];
	struct test_struct *shst;
	int cont = 1;

	memset(str, '\0', BUF_SIZE);

	if((shmid = shmget((key_t)5555, sizeof(struct test_struct), 666 | IPC_CREAT)) == -1) {
		printf("Failed to create shared memory.\n");
		exit(EXIT_FAILURE);
	}

	if((shmem = shmat(shmid, (void *)0, 0)) == NULL) {
		printf("Failed to attach shared memory.\n");
		exit(EXIT_FAILURE);
	}

	shst = (struct test_struct *)shmem;

	while(cont) {
		while(shst->written == 1) {
			sleep(1);
			printf("Waiting for consumer to complete.\n");
		}
		printf("Enter your input:");
		scanf("%s", str);

		strncpy(shst->buffer, str, BUF_SIZE);
		shst->written = 1;

		if((strncmp(str, "done", 4)) == 0)
			cont = 0;
	}

	if((shmdt(shmem)) == -1) {
		printf("Failed to detach shared memory.\n");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
