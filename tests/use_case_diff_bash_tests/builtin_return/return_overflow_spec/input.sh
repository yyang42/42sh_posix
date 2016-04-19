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
myfun -12
echo $?
myfun -42
echo $?
myfun 2147483647
echo $?
myfun 2147483648
echo $?
myfun -2147483647
echo $?
myfun -2147483648
echo $?
myfun -2147483649
echo $?
