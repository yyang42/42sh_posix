echo 'echo $0-$1-$2-$3; echo $@'  > /tmp/42sh_test_file.sh
$TESTED_SHELL /tmp/42sh_test_file.sh arg1 arg2
