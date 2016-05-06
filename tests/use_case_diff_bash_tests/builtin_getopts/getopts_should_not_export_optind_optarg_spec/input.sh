getopts a: opt -a arg
set | grep OPTIND=
set | grep OPTARG=
echo "===== bash"
bash -c 'set | grep OPTIND=; set | grep OPTARG=' | grep -v BASH_EXECUTION
