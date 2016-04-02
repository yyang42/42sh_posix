foo () {
	echo 'should exec'
	return 42
	echo 'should not exec'
}
foo
