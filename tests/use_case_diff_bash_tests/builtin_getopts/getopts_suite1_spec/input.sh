
foo () {
	echo "=================="
	echo $@
	echo "=================="
	OPTIND=1
	optstring=$1
	shift
	while getopts $optstring opt
	do
	    echo "opt: $opt // OPTIND: $OPTIND // exit_code: $?"
	    set | grep OPTARG=
	    case $opt in
	        a)    echo opt a with $OPTARG;;
	        b)    echo opt b;;
	        1)    echo opt 1;;
	        2)    echo opt 2;;
	        3)    echo opt 3;;
	        ?)    echo "opt not found: $opt"
	    esac
	    echo
	done
	shift $(($OPTIND - 1))
	echo "remainders: $@"
	echo
}

foo a:bc -a argA -b -c arg1 arg2
foo a:bc -1 -2 -3
foo a:bc -11
foo a:bc -W
foo a:bc -Wa
foo a:bc -Wall -Werror -Wextra
foo a:bc -- -a abc -b -c -1
foo a:bc -- -a abc -b -c -1
foo a:bc a -a abc
foo a:bc --
foo a:bc -
foo a:bc - - -
foo a:bc -- --
foo a:bc -a aaa,bbb,ccc -b -c
