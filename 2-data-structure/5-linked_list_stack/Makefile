CC = gcc
CFLAGS = -g -Wall
.PHONY:all
all: main.out
main.out: main.o stack.o
	$(CC) $(CFLAGS) $^ -o $@
main.o:main.c
stack.o: stack.c

clean:
	rm *.o *.out
