

CFLAGS=-g -Wall -std=c99

all: hello


hello: hello.c
	cc $(CFLAGS) -o hello hello.c


clean:
	rm -rf *.o *~hello
