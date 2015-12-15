#!/bin/sh

C_CYAN="\033[36;1m"
C_GREEN="\033[32;1m"
C_RED="\033[31;1m"
C_CLEAR="\033[0m"

BASEDIR=$(dirname $0)
ROOTDIR="$BASEDIR/.."
LOGFILE=$ROOTDIR/.tmp/valgrind.log
valgrind --leak-check=full --log-file="$LOGFILE" $BASEDIR/../tests/unit/test.out
cat $LOGFILE

cat $LOGFILE
if cat $LOGFILE | grep -q "definitely lost: 0 bytes in 0 blocks"
then
	echo $C_GREEN"=== Leaks test success   ==="$C_CLEAR
else
	echo   $C_RED"=== Leaks test fail      ==="$C_CLEAR
fi

if cat $LOGFILE | grep -q "Invalid read"
then
	echo   $C_RED"=== Invalid read fail    ==="$C_CLEAR
else
	echo $C_GREEN"=== Invalid read success ==="$C_CLEAR
fi
