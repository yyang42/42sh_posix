foo ()
{
	myvaraaa=default
	myvaraaa=value $1 &> /dev/null
	echo "$1 : $myvaraaa"
}

echo "echo abc" > /tmp/test_assign_effet_file
# foo . /tmp/test_assign_effet_file
foo :
foo alias aa=bb
# foo break 1
# foo cd `pwd`
# foo continue 1
foo echo abc
foo env
# foo eval echo abc
foo export
foo false
# foo fg
foo jobs
# foo kill
foo read abc </tmp/test_assign_effet_file
foo readonly
foo return -1
foo set -o
# foo setenv
foo shift 1
foo times
foo trap
foo true
foo umask
# foo unset
# foo unsetenv
foo wait
foo date
