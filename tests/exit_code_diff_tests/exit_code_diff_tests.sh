#!/bin/sh

C_CYAN="\033[36;1m"
C_GREEN="\033[32;1m"
C_RED="\033[31;1m"
C_CLEAR="\033[0m"

RENDU_PATH="`pwd`"
TESTS_ROOT_PATH="$RENDU_PATH/tests/exit_code_diff_tests/"

exit_status=0

make

if [ "$?" -ne "0" ]; then
    exit 1
fi

print_result ()
{
    if [ $1 -eq 0 ]
    then
        echo $C_GREEN"$2"$C_CLEAR"\c"
    else
        echo $C_RED"$2"$C_CLEAR"\c"
        exit_status=1
    fi
    echo " \c"
}

diff_test ()
{
    testsuite=$1
    testcase=$2
    testcase_path="$TESTS_ROOT_PATH/$testsuite/$testcase"
    testcase_tmp="$testcase_path/.tmp"
    testcase_tmp_exit_code="$testcase_tmp/actual_exit_code"

    mkdir -p $testcase_tmp
    rm -f $testcase_tmp/*
    $RENDU_PATH/42sh -y $testcase_path/input.sh &> /dev/null ; echo $? > $testcase_tmp_exit_code
    exec_res="$?"
    diff $testcase_path/expected_exit_code $testcase_tmp_exit_code
    exit_code_res="$?"
    exit_code_err="$?"

    print_result "$exec_res" exec
    print_result "$exit_code_res" exit_code
    echo "./42sh -y tests/exit_code_diff_tests/$testsuite/$testcase/input.sh"
}

echo $C_CYAN"====== START AST DIFF TESTS ======"$C_CLEAR
if ! `env | grep -q ^LAST_ONLY=`
then

    for CASE_PATH in $TESTS_ROOT_PATH/*; do
        if [ -d "${CASE_PATH}" ]; then
            for TEST_PATH in $CASE_PATH/*; do
                if [ -d "${TEST_PATH}" ]; then
                    diff_test `basename $CASE_PATH` `basename $TEST_PATH`
                fi
            done
        fi
    done

else

    diff_test first_tests echo_abc_123

fi
echo $C_CYAN"======  END TESTS  ======"$C_CLEAR

exit $exit_status
