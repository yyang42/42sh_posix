echo $?
myfn () {
	return $1
}

false
echo $?
true
echo $?
myfn 12 ; echo $?
