
foo () {
	echo "=================="
	echo $@
	echo "=================="
	OPTIND=0
	while getopts a:bc opt
	do
	    echo "opt: $opt // OPTIND: $OPTIND // exit_code: $?"
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

foo -a argA -b -c arg1 arg2
foo -1 -2 -3
foo -11
foo -W
foo -Wa
