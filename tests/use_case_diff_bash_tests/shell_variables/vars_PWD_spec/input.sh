foo () {
	path=$1
	cd $path
	echo $PWD
	pwd -P
}
foo `pwd`
foo /tmp
foo ~
