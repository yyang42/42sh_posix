foo () {
	echo abc
}
echo "=====1"
foo
echo "=====2"
env foo
echo "=====3"

