#this is Makefile
CFLAGS = -g -Wall
.PHONY:all
all:callback2.out callback1.out callback3.out
callback1.out:callback1.c
	gcc $(CFLAGS) $^ -o $@
callback2.out:callback2.c
	gcc $(CFLAGS) $^ -o $@
callback3.out:callback3.c
	gcc $(CFLAGS) $^ -o $@
.PHONY : clean
clean :
	rm *.out
