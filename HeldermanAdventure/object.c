#include <stdio.h>
#include "object.h"


static const char *tags0[] = {"field", NULL};
static const char *tags1[] = {"cave", NULL};
static const char *tags2[] = {"forest", NULL};
static const char *tags3[] = {"silver", "coin", "silver coin", NULL};
static const char *tags4[] = {"gold", "coin", "gold coin", NULL};
static const char *tags5[] = {"guard", "burly guard", NULL};
static const char *tags6[] = {"basket", NULL};
static const char *tags7[] = {"yourself", NULL};
static const char *tags8[] = {"east", "entrance", NULL};
static const char *tags9[] = {"west", "exit", NULL};
static const char *tags10[] = {"forest entrance", NULL};
static const char *tags11[] = {"forest exit",NULL};
static const char *tags12[] = {"west", "north", "south", "grass", NULL};
static const char *tags13[] = {"east", "north", "south", "rock", NULL};

OBJECT objs[] =
{
	{"an open grassy field", tags0, NULL, NULL},
	{"a little dark mountanside cave", tags1, NULL, NULL},
	{"dark miasma laden dark forest", tags2, NULL, NULL},
	{"a shining silver coin", tags3, field, NULL},
	{"a blessed lustrous golden coin", tags4, cave, NULL},
	{"a burly guard", tags5, field, NULL},
	{"a worn out brown basket", tags6, forest, NULL},
	{"yourself", tags7, field, NULL},
	{"a cave entrance to the east", tags8, field, cave},
	{"an exit to the west", tags9, cave, field},
	{"a forest entrance to the west", tags10, field, forest},
	{"an exit to the east ", tags11, forest, field},
	{"flat grass all around", tags12, field, NULL},
	{"solid rock all around", tags13, cave, NULL}
};
