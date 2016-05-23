
foo () {
	$TESTED_SHELL "$@" 2> /tmp/42sh_test_file
	echo status: $?
	cat /tmp/42sh_test_file | sed 's/bash/42sh/'
}

foo thisFileDoNotExist
