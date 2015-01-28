#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>

void my_handler(int signum)
{
	printf("Hahaha!!! Killer wont let you kill this process...\n");
}

int main(void)
{
	if(signal(SIGINT, my_handler) == SIG_ERR) {
		printf("Failed to register signal handler.\n");
		exit(EXIT_FAILURE);
	}

	while(1)
		sleep(1);

	exit(EXIT_SUCCESS);
}
