#!/bin/sh

C_CYAN="\033[36;1m"
C_GREEN="\033[32;1m"
C_RED="\033[31;1m"
C_CLEAR="\033[0m"

RENDU_PATH="`pwd`"
TESTS_PATH="$RENDU_PATH/tests/ast_diff_tests"

exit_status=0

make

print_result ()
{
	if [ $1 -eq 0 ]
	then
		echo $C_GREEN"OK"$C_CLEAR"\c"
	else
		echo $C_RED"KO"$C_CLEAR"\c"
		exit_status=1
	fi
}

diff_test ()
{
	testsuite=$1
	testcase=$2
	testcase_path="$TESTS_PATH/$testsuite/$testcase"
	testcase_tmp="$testcase_path/.tmp"
	testcase_tmp_stdout="$testcase_tmp/.actual_stdout"
	testcase_tmp_stderr="$testcase_tmp/.actual_stderr"

	mkdir -p testcase_tmp
	rm -f $testcase_tmp/*
	$RENDU_PATH/42sh -a $testcase_path/input.sh > $testcase_tmp_stdout 2> $testcase_tmp_stderr
	diff $testcase_path/expected_stdout $testcase_tmp_stdout
	print_result "$?"
	echo " stdout $testsuite/$testcase"
	diff $testcase_path/expected_stderr $testcase_tmp_stderr
	print_result "$?"
	echo " stderr $1/$2"
}

echo $C_CYAN"====== START TESTS ======"$C_CLEAR
if ! `env | grep -q ^LAST_ONLY=`
then

	diff_test first_tests echo_if

else

	diff_test tests/ast_diff_tests/test/syntax

fi
echo $C_CYAN"======  END TESTS  ======"$C_CLEAR

exit $exit_status
