#include <stdio.h>
#include "object.h"
static const char *tags0[] = { "field", NULL};
static const char *tags1[] = { "cave", NULL};
static const char *tags2[] = { "forest", NULL};
static const char *tags3[] = { "silver", "coin", "silver coin", NULL};
static const char *tags4[] = { "gold", "coin", "gold coin", NULL};
static const char *tags5[] = { "guard", "burly guard", NULL};
static const char *tags6[] = { "basket", NULL};
static const char *tags7[] = { "yourself", NULL};
static const char *tags8[] = { "east", "entrance", NULL};
static const char *tags9[] = { "west", "exit", NULL};
static const char *tags10[] = { "forest entrance", NULL};
static const char *tags11[] = { "forest exit", NULL};
static const char *tags12[] = { "west", "north", "south", "grass", NULL};
static const char *tags13[] = { "east", "north", "south", "rock", NULL};

OBJECT objs[] = {
	{	/* 0 = field */
		 "an open grassy field",
		tags0,
		NULL,
		NULL
	},
	{	/* 1 = cave */
		 "a little dark mountanside cave",
		tags1,
		NULL,
		NULL
	},
	{	/* 2 = forest */
		 "dark miasma laden dark forest",
		tags2,
		NULL,
		NULL
	},
	{	/* 3 = silver */
		 "a shining silver coin",
		tags3,
		 field,
		NULL
	},
	{	/* 4 = gold */
		 "a blessed lustrous golden coin",
		tags4,
		 cave,
		NULL
	},
	{	/* 5 = guard */
		 "a burly guard",
		tags5,
		 field,
		NULL
	},
	{	/* 6 = basket */
		 "a worn out brown basket",
		tags6,
		 forest,
		NULL
	},
	{	/* 7 = player */
		 "yourself",
		tags7,
		 field,
		NULL
	},
	{	/* 8 = enterCave */
		 "a cave entrance to the east",
		tags8,
		 field,
		 cave
	},
	{	/* 9 = exitCave */
		 "an exit to the west",
		tags9,
		 cave,
		 field
	},
	{	/* 10 = enterForest */
		 "a forest entrance to the west",
		tags10,
		 field,
		 forest
	},
	{	/* 11 = exitForest */
		 "an exit to the east",
		tags11,
		 forest,
		 field
	},
	{	/* 12 = wallField */
		 "flat grass all around",
		tags12,
		 field,
		NULL
	},
	{	/* 13 = wallCave */
		 "solid rock all around",
		tags13,
		 cave,
		NULL
	}
};
