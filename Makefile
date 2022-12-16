##
## Makefile
## vector2
##
## Created by Aarch-64 on 10/12/2022
## Copyright © 2022 Aarch-64. All rights reserved.
##

all:
	-echo "Building..."
	@make -C ./src

run:
	@make -C ./src run

clean:
	@make -C ./src clean	

install:
	@make -C ./src install

uninstall:
	@make -C ./src uninstall