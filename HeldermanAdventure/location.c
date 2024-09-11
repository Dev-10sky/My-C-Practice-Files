#include <stdio.h>
#include <string.h>
#include "object.h"
#include "misc.h"
#include "noun.h"

/*
struct location {
	const char *description;
	const char *tag;
}
locs[] = {
	{"an open grassy field", "field"},
	{"a dark miasma laden dark forest", "forest"},
	{"a little dark mountanside cave", "cave"}

};

#define numberOfLocations (sizeof locs / sizeof *locs)

static unsigned locationOfPlayer = 0;
*/

void executeLook(const char *noun)
{
	if (noun != NULL && strcmp(noun, "around") == 0)
	{
		printf("You are in %s.\n", player->location->description);
		listObjectsAtLocation(player->location);
	}
	else
	{
		printf("I don't understand what you want to see.\n");
	}
}

void executeGo(const char *noun)
{
/*
	unsigned i;
	for (i = 0; i < numberOfLocations; i++)
	{
		if (noun != NULL && strcmp(noun, locs[i].tag) == 0)
		{
			if (i == locationOfPlayer)
			{
				printf("You can't get much closer than this.\n");
			}
			else
			{
				printf("Ok.\n");
				locationOfPlayer = i;
				executeLook("around");
			}
			return;
		}
	}
	printf("I don't understand where you want to go. Please be clearer!\n");
*/

	OBJECT *obj = getVisible("where you want to go", noun);
	if (obj == NULL)
	{
		// getVisible handles this section
	}
	else if (obj->location == NULL && obj != player->location)
	{
		printf("Ok.\n");
		player->location = obj;
		executeLook("around");
	}
	else
	{
		printf("You can't get much closer than this.\n");
	}
}
