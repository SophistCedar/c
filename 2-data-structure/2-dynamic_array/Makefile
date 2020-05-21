CC = gcc
CFLAGS = -g -Wall

all: main.out

main.out: main.o dynamic_array.o
	$(CC) $(CFLAGS) $^ -o $@

main.o:main.c
dynamic_array.o: dynamic_array.c

clean: 
	rm *.o main.out
