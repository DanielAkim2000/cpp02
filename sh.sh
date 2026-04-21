#!/bin/bash

create_dirs() {
	local value="$1"

	for ((i = 0; i <= value; i++)); do
		mkdir -p "ex0$i"
		(cd "ex0$i" && touch Makefile main.cpp)
	done
}

value="$1"
create_dirs "$value"

#Other Solution

#DIRS= ex00 ex01 ex02 ex03

#for dir in $DIRS
#do
#	mkdir -p $dir;
#	cd $dir;
#	touch Makefile
#	cd ..
#done
