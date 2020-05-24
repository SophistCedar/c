CC = gcc
CFLAGS = -g -Wall
.PHONY:all
all: main.out
main.out: main.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm *.o *.out
