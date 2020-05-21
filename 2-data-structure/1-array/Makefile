#this is Makefile
CFLAGS = -g -Wall
objects = CArray.o
CArrayTests.out:CArrayTests.c $(objects)
	gcc $(CFLAGS) $^ -o $@
CArray.o:CArray.h

.PHONY:clean
clean:
	rm *.out $(objects)
