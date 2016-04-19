myfun () {
	echo start
	return $1;
	echo end
}

{
	myfun 42
	echo $?
	myfun 1
	echo $?
	myfun 0
	echo $?
	myfun -1
	echo $?
	myfun 254
	echo $?
	myfun 255
	echo $?
	myfun 256
	myfun 1000
	echo $?
} >/tmp/test_builtin_return_stdout 2> /tmp/test_builtin_return_stderr

cat /tmp/test_builtin_return_stdout | sed -e 's/.*input\.sh/CMD_PATH/g'
cat /tmp/test_builtin_return_stderr | sed -e 's/.*input\.sh/CMD_PATH/g'
