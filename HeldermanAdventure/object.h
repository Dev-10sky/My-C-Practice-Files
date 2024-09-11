#ifndef OBJECT_H
#define OBJECT_H

typedef struct  object {
	const char *description;
	const char *tag;
	struct object *location;
} OBJECT;

extern OBJECT objs[];

#define field (objs + 0)
#define cave (objs + 1)
#define forest (objs + 2)
#define silver (objs + 3)
#define gold (objs + 4)
#define guard (objs + 5)
#define basket (objs + 6)
#define player (objs + 7)

#define endOfObjs (objs + 8)


#endif
