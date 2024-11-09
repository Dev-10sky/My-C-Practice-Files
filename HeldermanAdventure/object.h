#ifndef OBJECT_H 
#define OBJECT_H

typedef struct object
{
    bool (*condition)(void);
    const char *description;
    const char **tags;
    struct object *location;
    struct object *destination;
    struct object *prospect;
    const char *details;
    const char *contents;
    const char *textGo;
    const char *gossip;
    int weight;
    int capacity;
    int health;
    int light;
    int impact;
    int trust;
    void (*open)(void);
    void (*close)(void);
    void (*lock)(void);
    void (*unlock)(void);
} OBJECT;

extern OBJECT *player, objs[];

#define heaven	(objs + 0)
#define respawn	(objs + 1)
#define heavenEWNS	(objs + 2)
#define waitingRoom	(objs + 3)
#define waitingRoomWall	(objs + 4)
#define nobody	(objs + 5)
#define field	(objs + 6)
#define cave	(objs + 7)
#define forest	(objs + 8)
#define silver	(objs + 9)
#define gold	(objs + 10)
#define guard	(objs + 11)
#define basket	(objs + 12)
#define jack	(objs + 13)
#define jill	(objs + 14)
#define enterCave	(objs + 15)
#define enterCaveBlocked	(objs + 16)
#define exitCave	(objs + 17)
#define enterForest	(objs + 18)
#define exitForest	(objs + 19)
#define wallField	(objs + 20)
#define wallCave	(objs + 21)
#define backroom	(objs + 22)
#define wallBackroom	(objs + 23)
#define openDoorToBackroom	(objs + 24)
#define closedDoorToBackroom	(objs + 25)
#define openDoorToCave	(objs + 26)
#define closedDoorToCave	(objs + 27)
#define openBox	(objs + 28)
#define closedBox	(objs + 29)
#define lockedBox	(objs + 30)
#define keyForBox	(objs + 31)
#define lampOff	(objs + 32)
#define lampOn	(objs + 33)
#define club	(objs + 34)
#define dagger	(objs + 35)

#define endOfObjs	(objs + 36)

#define validObject(obj)	((obj) != NULL && (*(obj)->condition)())

#endif
