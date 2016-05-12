foo () {
	$TESTED_SHELL "$@" 2> /tmp/42sh_test_file | sed 's/bash/42sh/'
	cat /tmp/42sh_test_file | sed 's/bash/42sh/'
}

foo -c 'echo $0_$1_$2_$3; echo $@' - a b
foo -i -c 'echo $0_$1_$2_$3; echo $@'
foo - -
foo - -i
foo -- --
foo -- -- abc

