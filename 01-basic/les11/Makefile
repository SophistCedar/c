CFLAGS = -g -Wall
.PHONY:all
all:struct.out struct2.out
struct.out:struct.c
	gcc $(CFLAGS) $^ -o $@
struct2.out:struct2.c
	gcc $(CFLAGS) $^ -o $@
.PHONY:clean
clean:
	rm *.out
