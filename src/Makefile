##
## Makefile
## vector
##
## Created by Aarch-64 on 10/12/2022
## Copyright © 2022 Aarch-64. All rights reserved.
##

CC=gcc
CLIBS=-lncurses -lvlc
CFLAGS=-Wall -Wextra -O2 -g -std=gnu99

OBJS= \
	files.o \
	game.o \
	main.o \
	menu.o \
	cli.o \
	vlc.o \
	screen.o

default: all

all: main

main: $(OBJS)
	$(CC) $(CFLAGS) -o vector $(OBJS) $(CLIBS)
	
clean:
	@rm -rf *.o vector
	
run: 
	@./vector

install:

	@sudo cp vector /usr/bin/ -r
	@sudo cp ../misc/logo.png /usr/share/icons/ -r
	@sudo cp ../misc/vector.desktop /usr/share/applications/ -r
	@sudo mkdir -p /opt/vector/
	@sudo cp ../music/ /opt/vector/ -r

uninstall:
	@sudo rm /usr/bin/vector
	@sudo rm /usr/share/icons/logo.png
	@sudo rm /usr/share/applications/vector.desktop
	@sudo rm ~/.vector/ -r
	@sudo rm /opt/vector/ -r
