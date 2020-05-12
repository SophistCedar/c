#this is Makefile
hello.out:max.o min.o hello.c
	gcc max.o min.o hello.c -o hello.out
max.o:max.c
	gcc -c max.c
min.o:min.c
	gcc -c min.c
.PHONY : clean
clean :
	rm *.o
