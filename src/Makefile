CC=gcc
CLIBS=-lncurses -lvlc
CFLAGS=-Wall -Wextra -O2 -std=gnu99

OBJS= \
	files.o \
	game.o \
	main.o \
	menu.o \
	cli.o \
	vlc.o

default: all

all: main

main: $(OBJS)
	$(CC) $(CFLAGS) -o ../vector $(OBJS) $(CLIBS)
	
clean:
	@rm -rf *.o ../vector
	
run: 
	@.././vector

install:
	@sudo cp ../vector /usr/bin/ -r
	@sudo cp ../misc/logo.png /usr/share/icons/ -r
	@sudo cp ../misc/vector.desktop /usr/share/applications/ -r

uninstall:
	@sudo rm /usr/bin/vector -r
	@sudo rm /usr/share/icons/logo.png
	@sudo rm /usr/share/applications/vector.desktop