
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
    int weight;
    int capacity;
    int health;
} OBJECT;

extern OBJECT objs[];

#define field	(objs + 0)
#define cave	(objs + 1)
#define forest	(objs + 2)
#define silver	(objs + 3)
#define gold	(objs + 4)
#define guard	(objs + 5)
#define basket	(objs + 6)
#define player	(objs + 7)
#define enterCave	(objs + 8)
#define enterCaveBlocked	(objs + 9)
#define exitCave	(objs + 10)
#define enterForest	(objs + 11)
#define exitForest	(objs + 12)
#define wallField	(objs + 13)
#define wallCave	(objs + 14)

#define endOfObjs	(objs + 15)

#define validObject(obj)	((obj) != NULL && (*(obj)->condition)())
