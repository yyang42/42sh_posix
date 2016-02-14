#!/bin/sh

C_CYAN="\033[36;1m"
C_GREEN="\033[32;1m"
C_RED="\033[31;1m"
C_CLEAR="\033[0m"

RENDU_PATH="`pwd`"
TESTS_ROOT_PATH="$RENDU_PATH/tests/ast_diff_tests"

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
    testcase_tmp_stdout="$testcase_tmp/actual_stdout"
    testcase_tmp_stderr="$testcase_tmp/actual_stderr"

    mkdir -p $testcase_tmp
    rm -f $testcase_tmp/*
    $RENDU_PATH/42sh -z $testcase_path/input.sh > $testcase_tmp_stdout 2> $testcase_tmp_stderr
    exec_res="$?"
    diff $testcase_path/expected_stdout $testcase_tmp_stdout
    stdout_res="$?"
    diff $testcase_path/expected_stderr $testcase_tmp_stderr
    stdout_err="$?"

    print_result "$exec_res" exec
    print_result "$stdout_res" stdout
    print_result "$stdout_err" stderr
    echo "./42sh -z tests/ast_diff_tests/$testsuite/$testcase/input.sh"
}

echo $C_CYAN"====== START AST DIFF TESTS ======"$C_CLEAR
if ! `env | grep -q ^LAST_ONLY=`
then

    for CASE_PATH in $TESTS_ROOT_PATH/*; do
        if [ -d "${CASE_PATH}" ]; then
            for TEST_PATH in $CASE_PATH/*; do
                if [ -d "${TEST_PATH}" ]; then
                    # mv $TESTS_ROOT_PATH/`basename $CASE_PATH`/`basename $TEST_PATH` $TESTS_ROOT_PATH/`basename $CASE_PATH`/`basename $TEST_PATH`_spec
                    # echo diff_test `basename $CASE_PATH` `basename $TEST_PATH`
                    diff_test `basename $CASE_PATH` `basename $TEST_PATH`
                fi
            done
        fi
    done

else

    diff_test brace_group simple_case
    diff_test redir redir
    diff_test list_pipe_andor empty_case
    diff_test list_pipe_andor simple_command
    diff_test simple_command empty_lines
    diff_test simple_command long
    diff_test simple_command no_newline
    diff_test simple_command simple_case
    diff_test if_clause simple_case
    diff_test if_clause without_else
fi
echo $C_CYAN"======  END TESTS  ======"$C_CLEAR

exit $exit_status
