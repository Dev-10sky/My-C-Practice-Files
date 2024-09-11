#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "location.h"


bool parseAndExecute(char *input)
{
	char *verb = strtok(input, " \n");
	char *noun = strtok(NULL, " \n");
	if (verb != NULL)
	{
		if (strcmp(verb, "quit") == 0)
		{
			return false;
		}
		else if (strcmp(verb, "look") == 0)
		{
			//printf("It is very dark in here.\n");
			executeLook(noun);
		}
		else if (strcmp(verb, "go") == 0)
		{
			//printf("It's too dark to go anywhere.\n");
			executeGo(noun);
		}
		else
		{
			printf("I don't know how to '%s'.\n", verb);
		}
	}
	return true;
}
