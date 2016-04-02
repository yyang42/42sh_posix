foo () {
	echo 'foo should exec'
	return
	echo 'foo should not exec'
}

bar () {
	echo 'bar should exec 1'
	foo
	echo 'bar should exec 2'
}

baz () {
	echo 'baz should exec 1'
	bar
	echo 'baz should exec 2'
}

baz
