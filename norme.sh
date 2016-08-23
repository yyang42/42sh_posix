#!/bin/bash

for dir in $(find srcs -type d); do
	list=$(for file in $dir/*; do [ -f $file ] && echo $file; done)
	if ! [ -z "$list" ]; then
		clear
		norminette $list
		read a
		while [ -z "$a" ]; do
			clear
			norminette $list
			read a
		done
	fi
done
