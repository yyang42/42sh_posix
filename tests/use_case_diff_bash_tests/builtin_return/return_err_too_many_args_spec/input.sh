foo () {
	echo 'should exec'
	return 1 2 3
	echo 'should not exec'
}
foo
