
foo () {
	echo "=================="
	echo $@
	echo "=================="
	OPTIND=1
	aflag=
	bflag=
	while getopts ab: name
	do
	    case $name in
	    a)    aflag=1;;
	    b)    bflag=1
	          bval="$OPTARG";;
	    ?)   printf "Usage: %s: [-a] [-b value] args\n" $0
	          return 1;;
	    esac
	done
	if [ ! -z "$aflag" ]; then
	    printf "Option -a specified\n"
	fi
	if [ ! -z "$bflag" ]; then
	    printf 'Option -b "%s" specified\n' "$bval"
	fi
	shift $(($OPTIND - 1))
	printf "Remaining arguments are: %s\n" "$*"
}

foo -a -b abc
foo -a
foo -b
foo -b 123
foo -b 123 456 789
foo -b -a 123 456 789










