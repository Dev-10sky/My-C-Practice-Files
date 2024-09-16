#ifndef MISC_H
#define MISC_H

// Distance from player character
typedef enum
{
	distSelf,
	distHeld,
	distHeldContained,
	distLocation,
	distHere,
	distHereContained,
	distOverThere,
	distNotHere,
	distUnknownObject
} DISTANCE;

extern bool isHolding(OBJECT *container, OBJECT *obj);
extern OBJECT *getPassage(OBJECT *from, OBJECT *to);
extern DISTANCE getDistance(OBJECT *from, OBJECT *to);
extern OBJECT *actorHere(void);
extern int listObjectsAtLocation(OBJECT *location);

#endif
