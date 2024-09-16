#include <stdio.h>
#include "object.h"


OBJECT objs[] =
{
	{"an open grassy field","field", NULL, NULL},
	{"a little dark mountanside cave","cave", NULL, NULL},
	{"dark miasma laden dark forest","forest", NULL, NULL},
	{"a shining silver coin","silver",field, NULL},
	{"a blessed lustrous golden coin","gold", cave, NULL},
	{"a burly guard","guard", field, NULL},
	{"a worn out brown basket","basket", forest, NULL},
	{"yourself","yourself", field, NULL},
	{"a cave entrance","entrance", field, cave},
	{"an exit","exit", cave, field},
	{"a forest entrance","forestEntrance", field, forest},
	{"a forest exit","forestExit", forest, field}
};
