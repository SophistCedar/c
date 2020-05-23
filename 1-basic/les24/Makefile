.PHONY:all
all:test.i test.s test.o test.out
test.i:test.c
		gcc -E test.c -o test.i	
test.s:test.c
		gcc -S test.c -o test.s	
test.o:test.c
		gcc -c test.c -o test.o	
test.out:test.o mymath.o
		gcc test.o mymath.o -o test.out	
.PHONY:clean
clean:
		rm *.i *.s *.o *.out