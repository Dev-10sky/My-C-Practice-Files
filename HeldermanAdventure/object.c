#include <stdbool.h>
#include <stdio.h>
#include "object.h"
#include "toggle.h"
static const char *tags0[] = { "east", "west", "north", "south", NULL};
static const char *tags1[] = { "field", NULL};
static const char *tags2[] = { "cave", NULL};
static const char *tags3[] = { "forest", NULL};
static const char *tags4[] = { "silver", "coin", "silver coin", NULL};
static const char *tags5[] = { "gold", "coin", "gold coin", NULL};
static const char *tags6[] = { "guard", "burly guard", NULL};
static const char *tags7[] = { "basket", NULL};
static const char *tags8[] = { "yourself", NULL};
static bool condition9(void)  { return guard->health == 0 || silver->location == guard; }
static const char *tags9[] = { "east", "entrance", NULL};
static bool condition10(void)  { return !(*enterCave->condition)(); }
static const char *tags10[] = { "east", "entrance", NULL};
static const char *tags11[] = { "west", "exit", NULL};
static const char *tags12[] = { "forest entrance", NULL};
static const char *tags13[] = { "forest exit", NULL};
static const char *tags14[] = { "west", "north", "south", "grass", NULL};
static const char *tags15[] = { "east", "north", "rock", NULL};
static const char *tags16[] = { "backroom", NULL};
static const char *tags17[] = { "east", "west", "south", "rock", NULL};
static const char *tags18[] = { "south", "door", "doorway", NULL};
static const char *tags19[] = { "south", "door", "doorway", NULL};
static const char *tags20[] = { "north", "door", "doorway", NULL};
static const char *tags21[] = { "north", "door", "doorway", NULL};
static const char *tags22[] = { "box", "wooden box", NULL};
static const char *tags23[] = { "box", "wooden box", NULL};
static const char *tags24[] = { "box", "wooden box", NULL};
static const char *tags25[] = { "key", "tiny key", NULL};
static const char *tags26[] = { "lamp", NULL};
static const char *tags27[] = { "lamp", NULL};

static bool alwaysTrue(void) { return true; }

OBJECT objs[] = {
	{	/* 0 = gossipEWNS */
		alwaysTrue,
		NULL,
		tags0,
		NULL,
		NULL,
		NULL,
		"You see nothing special.",
		"You see",
		"You can't get much closer than this.",
		 "It's just a direction on the compass.",
		99,
		0,
		0,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 1 = field */
		alwaysTrue,
		 "an open grassy field",
		tags1,
		NULL,
		NULL,
		NULL,
		 "The grassy field is a wide and calming space under a nightime sky.",
		"You see",
		"You can't get much closer than this.",
		 "It seems not often treaded.",
		99,
		 9999,
		0,
		 100,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 2 = cave */
		alwaysTrue,
		 "a little dark mountanside cave",
		tags2,
		NULL,
		NULL,
		NULL,
		 "The mountainside cave is a cold, dark, and rocky chamber.",
		"You see",
		"You can't get much closer than this.",
		 "It's dark in there; better bring a light source!.",
		99,
		 9999,
		0,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 3 = forest */
		alwaysTrue,
		 "dark miasma laden dark forest",
		tags3,
		NULL,
		NULL,
		NULL,
		 "The forest is an old, dark, and aged area with a tree cover obscuring the sky.",
		"You see",
		"You can't get much closer than this.",
		 "No one really knows what goes on in there.",
		99,
		 9999,
		0,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 4 = silver */
		alwaysTrue,
		 "a shining silver coin",
		tags4,
		 field,
		NULL,
		NULL,
		 "The coin has stalks of wheat tied with a ribbon engraved onto it.",
		"You see",
		"You can't get much closer than this.",
		 "Money makes the world go round...",
		 1,
		0,
		0,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 5 = gold */
		alwaysTrue,
		 "a blessed lustrous golden coin",
		tags5,
		 openBox,
		NULL,
		NULL,
		 "The coin is old and clearly has no known denomination and is a priceless aretefact.",
		"You see",
		"You can't get much closer than this.",
		 "Money makes the world go round...",
		 1,
		0,
		0,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 6 = guard */
		alwaysTrue,
		 "a burly guard",
		tags6,
		 field,
		NULL,
		NULL,
		 "The guard is a big and burly guy.",
		 "He has",
		"You can't get much closer than this.",
		 "He does his job stiffly but, every gear can be greased...",
		99,
		 20,
		 100,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 7 = basket */
		alwaysTrue,
		 "a worn out brown basket",
		tags7,
		 forest,
		NULL,
		NULL,
		 "The basket is an wood woven creation with a few holes in it.",
		"You see",
		"You can't get much closer than this.",
		 "Some say baskets are the last great human invention...",
		 3,
		 60,
		0,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 8 = player */
		alwaysTrue,
		 "yourself",
		tags8,
		 field,
		NULL,
		NULL,
		 "You need a mirror or reflective surface to view yourself.",
		 "You have",
		"You can't get much closer than this.",
		 "You're a new face huh? Dont get many of those round here.",
		99,
		 20,
		 100,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 9 = enterCave */
		condition9,
		 "a cave entrance to the east",
		tags9,
		 field,
		 cave,
		 cave,
		 "The entrace is a wide opening in the mountain with a stone runic plaque above it.",
		"You see",
		 "You walk into the cave.",
		"I know nothing about that.",
		99,
		0,
		0,
		0,
		 isAlreadyOpen,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 10 = enterCaveBlocked */
		condition10,
		 "a cave entrance to the east",
		tags10,
		 field,
		NULL,
		 cave,
		 "The entrace is a wide opening in the mountain with a stone runic plaque above it.",
		"You see",
		 "The guard is stopping you from entering the cave.",
		"I know nothing about that.",
		99,
		0,
		0,
		0,
		 isAlreadyOpen,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 11 = exitCave */
		alwaysTrue,
		 "an exit to the west",
		tags11,
		 cave,
		 field,
		 field,
		 "The moon hangs in the sky in the opening through the cave wall.",
		"You see",
		 "You leave the cave.",
		"I know nothing about that.",
		99,
		0,
		0,
		0,
		 isAlreadyOpen,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 12 = enterForest */
		alwaysTrue,
		 "a forest entrance to the west",
		tags12,
		 field,
		NULL,
		 forest,
		 "The entrance is a gravel pathway with twisted trees forming the circular opening.",
		"You see",
		 "There is nothing stopping you from going forward.",
		"I know nothing about that.",
		99,
		0,
		0,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 13 = exitForest */
		alwaysTrue,
		 "an exit to the east",
		tags13,
		 forest,
		 field,
		 field,
		 "The moon hangs above the sky that can be made out through the tree cover.",
		"You see",
		 "You walk out of the dark forest.",
		"I know nothing about that.",
		99,
		0,
		0,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 14 = wallField */
		alwaysTrue,
		 "flat grass all around",
		tags14,
		 field,
		NULL,
		NULL,
		 "The field is surrounded by trees, roots, and undergrowth.",
		"You see",
		 "Dense forest growth is blocking the way.",
		 "You cannot go there, its pretty hard to get through.",
		99,
		0,
		0,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 15 = wallCave */
		alwaysTrue,
		 "solid rock all around",
		tags15,
		 cave,
		NULL,
		NULL,
		 "Carved into the stone is a secret password 'abcd'.",
		"You see",
		 "Solid rock is blocking the way.",
		 "You cannot go there, its just rock.",
		99,
		0,
		0,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 16 = backroom */
		alwaysTrue,
		 "a backroom",
		tags16,
		NULL,
		NULL,
		NULL,
		 "The room is dusty and messy.",
		"You see",
		"You can't get much closer than this.",
		 "There is definitely something in here worth hiding it away.",
		99,
		 9999,
		0,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 17 = wallBackroom */
		alwaysTrue,
		 "solid rock all around",
		tags17,
		 backroom,
		NULL,
		NULL,
		 "Rocky walls with embedded black stones.",
		"You see",
		 "Solid rock is blocking the way.",
		 "You cannot go there, its just bland wood.",
		99,
		0,
		0,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 18 = openDoorToBackroom */
		alwaysTrue,
		 "an open door to the south",
		tags18,
		NULL,
		 backroom,
		 backroom,
		 "The door is open.",
		"You see",
		 "You walk through the door into the backroom.",
		"I know nothing about that.",
		99,
		0,
		0,
		0,
		 isAlreadyOpen,
		 toggleDoorToBackroom,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 19 = closedDoorToBackroom */
		alwaysTrue,
		 "a closed door to the south",
		tags19,
		 cave,
		NULL,
		 backroom,
		 "The door is closed.",
		"You see",
		 "The door is closed.",
		"I know nothing about that.",
		99,
		0,
		0,
		0,
		 toggleDoorToBackroom,
		 isAlreadyClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 20 = openDoorToCave */
		alwaysTrue,
		 "an open door to the north",
		tags20,
		NULL,
		 cave,
		 cave,
		 "The door is open.",
		"You see",
		 "You walk through the door into the cave.",
		"I know nothing about that.",
		99,
		0,
		0,
		0,
		 isAlreadyOpen,
		 toggleDoorToCave,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 21 = closedDoorToCave */
		alwaysTrue,
		 "a closed door to the north",
		tags21,
		 backroom,
		NULL,
		 cave,
		 "The door is closed.",
		"You see",
		 "The door is closed.",
		"I know nothing about that.",
		99,
		0,
		0,
		0,
		 toggleDoorToCave,
		 isAlreadyClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 22 = openBox */
		alwaysTrue,
		 "a wooden box",
		tags22,
		NULL,
		NULL,
		NULL,
		 "The box is open.",
		"You see",
		"You can't get much closer than this.",
		 "You need a key to open it.",
		 5,
		 20,
		0,
		0,
		 isAlreadyOpen,
		 toggleBox,
		 isStillOpen,
		 isAlreadyOpen
	},
	{	/* 23 = closedBox */
		alwaysTrue,
		 "a wooden box",
		tags23,
		NULL,
		NULL,
		NULL,
		 "The box is closed.",
		"You see",
		"You can't get much closer than this.",
		"I know nothing about that.",
		 5,
		0,
		0,
		0,
		 toggleBox,
		 isAlreadyClosed,
		 toggleBoxLock,
		 isAlreadyUnlocked
	},
	{	/* 24 = lockedBox */
		alwaysTrue,
		 "a wooden box",
		tags24,
		 backroom,
		NULL,
		NULL,
		 "The box is closed.",
		"You see",
		"You can't get much closer than this.",
		"I know nothing about that.",
		 5,
		0,
		0,
		0,
		 isStillLocked,
		 isAlreadyClosed,
		 isAlreadyLocked,
		 toggleBoxLock
	},
	{	/* 25 = keyForBox */
		alwaysTrue,
		 "a tiny key",
		tags25,
		 cave,
		NULL,
		NULL,
		 "The key is really small and shiny.",
		"You see",
		"You can't get much closer than this.",
		 "A small key opens a small lock.",
		 1,
		0,
		0,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 26 = lampOff */
		alwaysTrue,
		 "a lamp",
		tags26,
		 field,
		NULL,
		NULL,
		 "The lamp is off.",
		"You see",
		"You can't get much closer than this.",
		 "Essential tool for dark areas.",
		 5,
		0,
		0,
		0,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	},
	{	/* 27 = lampOn */
		alwaysTrue,
		 "a lamp",
		tags27,
		NULL,
		NULL,
		NULL,
		 "The lamp is on.",
		"You see",
		"You can't get much closer than this.",
		"I know nothing about that.",
		 5,
		0,
		0,
		 100,
		cannotBeOpened,
		cannotBeClosed,
		cannotBeLocked,
		cannotBeUnlocked
	}
};
