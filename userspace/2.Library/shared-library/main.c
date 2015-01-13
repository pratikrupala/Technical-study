#include <stdio.h>
#include "lib.h"

int main(void)
{
	int n = 0;

	printf("Enter any number:");
	scanf("%d", &n);

	if(n % 2)
		black("black");
	else
		white("white");

	return 0;
}
