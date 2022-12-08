CC=gcc
CLIBS=-lncurses
CFLAGS=-Wall -Wextra -O2 -std=gnu99

OBJS= \
	src/files.o \
	src/game.o \
	src/main.o \
	src/menu.o \
	src/cli.o

default: all

all: main

main: $(OBJS)
	sudo $(CC) $(CFLAGS) -o vector $(OBJS) $(CLIBS)
	
clean:
	@sudo rm -rf src/*.o vector
	
run: 
	@./vector

install:

	@sudo cp vector /usr/bin/ -r
	-sudo cp misc/vector.desktop /usr/share/applications/ -r
	-sudo cp misc/logo.png ~/.local/share/icons/ -r

uninstall:
	@sudo rm /usr/bin/vector -r
	-sudo rm /usr/share/applications/vector.desktop
	-sudo rm ~/.local/share/icons/logo.png