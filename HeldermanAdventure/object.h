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
    void (*open)(void);
    void (*close)(void);
    void (*lock)(void);
    void (*unlock)(void);
} OBJECT;

extern OBJECT objs[];

#define gossipEWNS	(objs + 0)
#define field	(objs + 1)
#define cave	(objs + 2)
#define forest	(objs + 3)
#define silver	(objs + 4)
#define gold	(objs + 5)
#define guard	(objs + 6)
#define basket	(objs + 7)
#define player	(objs + 8)
#define enterCave	(objs + 9)
#define enterCaveBlocked	(objs + 10)
#define exitCave	(objs + 11)
#define enterForest	(objs + 12)
#define exitForest	(objs + 13)
#define wallField	(objs + 14)
#define wallCave	(objs + 15)
#define backroom	(objs + 16)
#define wallBackroom	(objs + 17)
#define openDoorToBackroom	(objs + 18)
#define closedDoorToBackroom	(objs + 19)
#define openDoorToCave	(objs + 20)
#define closedDoorToCave	(objs + 21)
#define openBox	(objs + 22)
#define closedBox	(objs + 23)
#define lockedBox	(objs + 24)
#define keyForBox	(objs + 25)
#define lampOff	(objs + 26)
#define lampOn	(objs + 27)

#define endOfObjs	(objs + 28)

#define validObject(obj)	((obj) != NULL && (*(obj)->condition)())

#endif
