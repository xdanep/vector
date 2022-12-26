##
## Makefile
## vector
##
## Created by Aarch-64 on 10/12/2022
## Copyright © 2022 Aarch-64. All rights reserved.
##

CC=gcc
CLIBS=-lncursesw -lSDL2_mixer -lSDL2
CFLAGS=-pipe -O2 -flto -Wall -Wextra -fPIC -std=gnu17

OBJS= \
	cmd.o \
	files.o \
	game.o \
	gameplay.o \
	main.o \
	menu.o \
	screen.o \
	sound.o 

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
	@sudo rm ~/.config/vector/ -r
	@sudo rm /opt/vector/ -r