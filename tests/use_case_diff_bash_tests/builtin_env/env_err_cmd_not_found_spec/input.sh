{
	env myvar=aa -i echo bla
	echo status $?
} 2>&1 | sed -e 's/.*input\.sh/CMD_PATH/g'
