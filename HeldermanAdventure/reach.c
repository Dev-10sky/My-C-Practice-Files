#include <stdbool.h>
#include <stdio.h>
#include "object.h"
#include "misc.h"
#include "noun.h"

OBJECT *reachableObject(const char *intention, const char *noun)
{
    OBJECT *obj = getVisible(intention, noun);
    switch (getDistance(player,obj))
    {
    case distSelf:
        printf("You should not be doing that to yourself.\n");
        break;
    // case distHeld:
    case distHeldContained:
        printf("You would have to get it from %s first.\n",
                obj->location->description);
        break;
    case distOverThere:
        printf("Too far away, move closer please.\n");
        break;
    case distNotHere:
    case distUnknownObject:
        // redundant due to getVisible
        break;
    default:
        return obj;
    }
    return NULL;
}