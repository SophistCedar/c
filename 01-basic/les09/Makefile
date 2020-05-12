#this is Makefile
.PHONY:all
all:server.out client.out
server.out:server.c
	gcc server.c -o server.out
client.out:client.c
	gcc client.c -o client.out
.PHONY : clean
clean :
	rm *.out