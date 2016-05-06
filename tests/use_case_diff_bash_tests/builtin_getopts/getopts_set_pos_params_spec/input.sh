set -- -a argA -b -c arg1 arg2

while getopts a:bc opt
do
    echo "opt: $opt // OPTIND: $OPTIND"
    case $opt in
        a)    echo opt a with $OPTARG;;
        b)    echo opt b;;
        ?)    echo "opt not found: $opt"
    esac
    echo
done

shift $(($OPTIND - 1))
echo "remainders: $@"
