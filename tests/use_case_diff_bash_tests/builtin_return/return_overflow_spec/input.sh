myfun () {
	echo start
	return $1;
	echo end
}
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
echo $?
