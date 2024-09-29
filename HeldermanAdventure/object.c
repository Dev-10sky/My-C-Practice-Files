#include <stdbool.h>
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
static bool condition8(void)  { return guard->health == 0 || silver->location == guard; }
static const char *tags8[] = { "east", "entrance", NULL};
static bool condition9(void)  { return !(*enterCave->condition)(); }
static const char *tags9[] = { "east", "entrance", NULL};
static const char *tags10[] = { "west", "exit", NULL};
static const char *tags11[] = { "forest entrance", NULL};
static const char *tags12[] = { "forest exit", NULL};
static const char *tags13[] = { "west", "north", "south", "grass", NULL};
static const char *tags14[] = { "east", "north", "south", "rock", NULL};

static bool alwaysTrue(void) { return true; }

OBJECT objs[] = {
	{	/* 0 = field */
		alwaysTrue,
		 "an open grassy field",
		tags0,
		NULL,
		NULL,
		NULL,
		 "The grassy field is a wide and calming space under a nightime sky.",
		"You see",
		"You can't get much closer than this.",
		99,
		 9999,
		0
	},
	{	/* 1 = cave */
		alwaysTrue,
		 "a little dark mountanside cave",
		tags1,
		NULL,
		NULL,
		NULL,
		 "The mountainside cave is a cold, dark, and rocky chamber.",
		"You see",
		"You can't get much closer than this.",
		99,
		 9999,
		0
	},
	{	/* 2 = forest */
		alwaysTrue,
		 "dark miasma laden dark forest",
		tags2,
		NULL,
		NULL,
		NULL,
		 "The forest is an old, dark, and aged area with a tree cover obscuring the sky.",
		"You see",
		"You can't get much closer than this.",
		99,
		 9999,
		0
	},
	{	/* 3 = silver */
		alwaysTrue,
		 "a shining silver coin",
		tags3,
		 field,
		NULL,
		NULL,
		 "The coin has stalks of wheat tiede with a ribbon engraved onto it.",
		"You see",
		"You can't get much closer than this.",
		 1,
		0,
		0
	},
	{	/* 4 = gold */
		alwaysTrue,
		 "a blessed lustrous golden coin",
		tags4,
		 cave,
		NULL,
		NULL,
		 "The coin is old and clearly has no known denomination and is a priceless aretefact.",
		"You see",
		"You can't get much closer than this.",
		 1,
		0,
		0
	},
	{	/* 5 = guard */
		alwaysTrue,
		 "a burly guard",
		tags5,
		 field,
		NULL,
		NULL,
		 "The guard is a big and burly guy.",
		 "He has",
		"You can't get much closer than this.",
		99,
		 20,
		 100
	},
	{	/* 6 = basket */
		alwaysTrue,
		 "a worn out brown basket",
		tags6,
		 forest,
		NULL,
		NULL,
		 "The basket is an wood woven creation with a few holes in it.",
		"You see",
		"You can't get much closer than this.",
		 3,
		 60,
		0
	},
	{	/* 7 = player */
		alwaysTrue,
		 "yourself",
		tags7,
		 field,
		NULL,
		NULL,
		 "You need a mirror or reflective surface to view yourself.",
		 "You have",
		"You can't get much closer than this.",
		99,
		 20,
		 100
	},
	{	/* 8 = enterCave */
		condition8,
		 "a cave entrance to the east",
		tags8,
		 field,
		 cave,
		 cave,
		 "The entrace is a wide opening in the mountain with a stone runic plaque above it.",
		"You see",
		 "You walk into the cave.",
		99,
		0,
		0
	},
	{	/* 9 = enterCaveBlocked */
		condition9,
		 "a cave entrance to the east",
		tags9,
		 field,
		NULL,
		 cave,
		 "The entrace is a wide opening in the mountain with a stone runic plaque above it.",
		"You see",
		 "The guard is stopping you from entering the cave.",
		99,
		0,
		0
	},
	{	/* 10 = exitCave */
		alwaysTrue,
		 "an exit to the west",
		tags10,
		 cave,
		 field,
		 field,
		 "The moon hangs in the sky in the opening through the cave wall.",
		"You see",
		 "You leave the cave.",
		99,
		0,
		0
	},
	{	/* 11 = enterForest */
		alwaysTrue,
		 "a forest entrance to the west",
		tags11,
		 field,
		NULL,
		 forest,
		 "The entrance is a gravel pathway with twisted trees forming the circular opening.",
		"You see",
		 "There is nothing stopping you from going forward.",
		99,
		0,
		0
	},
	{	/* 12 = exitForest */
		alwaysTrue,
		 "an exit to the east",
		tags12,
		 forest,
		 field,
		 field,
		 "The moon hangs above the sky that can be made out through the tree cover.",
		"You see",
		 "You walk out of the dark forest.",
		99,
		0,
		0
	},
	{	/* 13 = wallField */
		alwaysTrue,
		 "flat grass all around",
		tags13,
		 field,
		NULL,
		NULL,
		 "The field is surrounded by trees, roots, and undergrowth.",
		"You see",
		 "Dense forest growth is blocking the way.",
		99,
		0,
		0
	},
	{	/* 14 = wallCave */
		alwaysTrue,
		 "solid rock all around",
		tags14,
		 cave,
		NULL,
		NULL,
		 "Carved into the stone is a secret password 'abcd'.",
		"You see",
		 "Solid rock is blocking the way.",
		99,
		0,
		0
	}
};
