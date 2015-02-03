#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(void)
{
	if((syscall(321)) < 0) {
		fprintf(stderr, "Call to newly added syscall failed with error code: %d\n", errno);
		exit(EXIT_FAILURE);
	}
	
	exit(EXIT_SUCCESS);
}
