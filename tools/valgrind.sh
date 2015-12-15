#!/bin/bash

BASEDIR=$(dirname $0)

valgrind --leak-check=full --log-fd=1 $BASEDIR/../tests/unit/test.out | tee /dev/stderr | grep "definitely lost: 0 bytes in 0 blocks"
