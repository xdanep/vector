CC=clang
CLIBS=-lncurses
CFLAGS=-Wall -Wextra -O2 -std=gnu99

OBJS= \
	files.o \
	game.o \
	main.o \
	menu.o

default: all

all: main

main: $(OBJS)
	$(CC) $(CFLAGS) -o vector $(OBJS) $(CLIBS)
	
clean:
	@rm main.o files.o game.o menu.o vector
	
run: 
	@./vector

