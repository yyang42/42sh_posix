foo () {
	myvar="$1"
	set | grep myvar=
}

foo "'"
