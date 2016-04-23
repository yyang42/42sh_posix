myfun () {
	return $1
}
echo "========1"
myfun 0 || echo $?
echo "========2"
myfun 1 || echo $?
