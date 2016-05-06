
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

foo a:bc -a
foo a:bc -a -b
foo a:bc -a -b -c
foo :a:bc -a -b
foo :a:bc -a -b -a -b
foo a:bc -a -b
foo a:bc -a --
foo :a:bc -a -a
foo :a:bc -a -b
foo :a:bc -a --
foo :a:bc -a -- -a --
foo :a:bc -a -- --
foo :a:bc -- -a --
