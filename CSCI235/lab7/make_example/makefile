#makefile for make_example
CC=gcc
CFLAGS= -c-Wall

OBJECTS = hellofunc.c hellomake.c

all: prog

prog: $(OBJECTS)
	$(CC) $(OBJECTS) -o prog -lm


%o: %.c
	$(CC) $(CFLAGS) $<


 

clean: 
	rm -rf *.o
