foo ()
{
	myvaraaa=default
	myvaraaa=value $1 &> /dev/null
	echo "$1 : $myvaraaa"
}

echo "echo abc" > /tmp/test_assign_effet_file

foo :
foo alias aa=bb
foo echo abc
foo env
foo export
foo false
foo jobs
foo read abc </tmp/test_assign_effet_file
foo readonly
foo return -1
foo set -o
foo shift 1
foo times
foo trap
foo true
foo umask
foo wait
foo date

# not testable
# foo break 1
# foo cd `pwd`
# foo continue 1
# foo eval echo abc
# foo fg
# foo kill
# foo setenv
# foo unset
# foo unsetenv
