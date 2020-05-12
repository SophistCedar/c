#this is Makefile
.PHONY:all
all:data.out stack.out heap.out main.out
data.out:data.c
	gcc -g data.c -o data.out
stack.out:stack.c
	gcc -g stack.c -o stack.out
heap.out:heap.c
	gcc -g heap.c -o heap.out
main.out:main.c
	gcc -g main.c -o main.out
.PHONY : clean
clean :
	rm *.out