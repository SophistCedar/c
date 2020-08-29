CC = gcc
CFLAGS = -g
INCLUDES = .
VPATH = $(INCLUDES)
II_INCLUDES = $(addprefix -I,$(INCLUDES))
src = $(wildcard *.c)
objs = $(patsubst %.c,%.o,$(src))

#EXEONLYONE = 1
ifdef EXEONLYONE
main:$(objs)
	$(CC) $(CFLAGS) $(II_INCLUDES) $^ -o $@
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
.PHONY: clean
clean:
	rm *.o main
else
exe = $(patsubst %.c,%,$(src))
all:$(exe)
%:%.c
	$(CC) $(CFLAGS) $(II_INCLUDES) $^ -o $@
.PHONY: clean
clean:
	rm $(exe) 
endif

