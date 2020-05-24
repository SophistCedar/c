CC = gcc
CFLAGS = -g -Wall
.PHONY:all
all: main.out
main.out: main.o queue.o
	$(CC) $(CFLAGS) $^ -o $@
main.o:main.c
queue.o: queue.c

clean:
	rm *.o *.out
