CC = gcc
CFLAGS = -g -Wall
objects = main.o list.o

all: main.out
main.out:$(objects)
	$(CC) $(CFLAGS) $^ -o $@
# .o 文件不写也会被自动推导出来
main.o:main.c
list.o:list.c

clean:
	rm *o *.out
