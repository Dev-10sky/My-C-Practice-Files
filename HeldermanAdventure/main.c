#include <stdbool.h>
#include <stdio.h>
#include "parsexec.h"

static char input[100] = "look around";

static bool getInput(void)
{
	printf("\n--> ");
	return fgets(input, sizeof input, stdin) != NULL;
}


int main()
{
	printf("Welcome to the Little Cave Adventure. \n");
//	printf("It's kinda really dark in here. \n");
	while (parseAndExecute(input) && getInput());
	printf("\nBye!\n");
	return 0;
}
