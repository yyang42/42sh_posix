#!/bin/sh

# alias v='make && valgrind  --gen-suppressions=all --num-callers=50 ./42sh'

while true; do clear; cat valgrind.log | grep 'in loss'| tail -n 50 ; sleep 1; done
