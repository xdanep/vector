CC=gcc
CLIBS=-lncurses
CFLAGS=-Wall -Wextra -O2 -std=gnu99

OBJS= \
	files.o \
	game.o \
	main.o \
	menu.o \
	cli.o

default: all

all: main

main: $(OBJS)
	$(CC) $(CFLAGS) -o vector $(OBJS) $(CLIBS)
	
clean:
	@rm main.o files.o game.o menu.o cli.o vector misc/vector
	
run: 
	@./vector

install:

	@cp vector misc/ -r
	-sudo cp misc/vector /usr/bin/ -r
	-sudo cp misc/vector.desktop ~/.local/share/applications/ -r
	-sudo cp misc/logo.png ~/.local/share/icons/ -r