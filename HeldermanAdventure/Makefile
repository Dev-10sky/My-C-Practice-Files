

CFLAGS=-g -Wall -std=c99

all: main


#main: main.c parsexec.o parsexec.h location.o location.h 
#object.o object.h noun.o noun.h misc.o misc.h
#	cc $(CFLAGS) -o main parsexec.o location.o object.o object main.c
main: main.c parsexec.h location.h object.h noun.h misc.h move.h inventory.h
	cc $(CFLAGS) -o main main.c parsexec.c location.c object.c noun.c misc.c move.c inventory.c

clean:
	rm -rf *.o main
