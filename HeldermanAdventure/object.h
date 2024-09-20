
typedef struct object
{
    const char *description;
    const char **tags;
    struct object *location;
    struct object *destination;
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
#define exitCave	(objs + 9)
#define enterForest	(objs + 10)
#define exitForest	(objs + 11)
#define wallField	(objs + 12)
#define wallCave	(objs + 13)

#define endOfObjs	(objs + 14)
