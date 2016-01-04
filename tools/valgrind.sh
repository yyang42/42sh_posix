#!/bin/sh

C_CYAN="\033[36;1m"
C_GREEN="\033[32;1m"
C_RED="\033[31;1m"
C_CLEAR="\033[0m"

BASEDIR=$(dirname $0)
ROOTDIR="$BASEDIR/.."
LOGFILE=$ROOTDIR/.tmp/valgrind.log
make check_unit
valgrind --leak-check=full --num-callers=40 --log-file="$LOGFILE" $BASEDIR/../tests/unit/test.out
cat $LOGFILE

cat $LOGFILE

error=0

if grep -q "definitely lost: 0 bytes in 0 blocks" $LOGFILE || grep -q "in use at exit: 0 bytes in 0 blocks" $LOGFILE
then
	echo $C_GREEN"=== Leaks test success   ==="$C_CLEAR
else
	echo   $C_RED"=== Leaks test fail      ==="$C_CLEAR
	error=1
fi

if cat $LOGFILE | grep -q "Invalid read"
then
	echo   $C_RED"=== Invalid read fail    ==="$C_CLEAR
	error=1
else
	echo $C_GREEN"=== Invalid read success ==="$C_CLEAR
fi

exit $error
