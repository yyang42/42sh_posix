echo "start"

echo abc &
sleep 0.1
LASTPID="$!"

jobs -p > /tmp/expan_special_test_file_pid
read jobpid < /tmp/expan_special_test_file_pid

if [ "$jobpid" = "$LASTPID" ]; then
	echo "equal"
else
	echo "not equal"
fi

if [ "$LASTPID" -eq "$LASTPID" ]
then
    echo "is a number"
else
    echo "is not a number"
fi

echo "end"
