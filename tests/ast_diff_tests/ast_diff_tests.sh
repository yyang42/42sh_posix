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
    testcase_path="$TESTS_ROOT_PATH/$testsuite/$testcase"
    testcase_tmp="$testcase_path/.tmp"
    testcase_tmp_stdout="$testcase_tmp/actual_stdout"
    testcase_tmp_stderr="$testcase_tmp/actual_stderr"

    mkdir -p $testcase_tmp
    rm -f $testcase_tmp/*
    $RENDU_PATH/42sh -z $testcase_path/input.sh > $testcase_tmp_stdout 2> $testcase_tmp_stderr
    echo "./42sh -z tests/ast_diff_tests/$testsuite/$testcase/input.sh"
    diff $testcase_path/expected_stdout $testcase_tmp_stdout
    print_result "$?"
    echo " stdout $testsuite/$testcase"
    diff $testcase_path/expected_stderr $testcase_tmp_stderr
    print_result "$?"
    echo " stderr $1/$2"
}

echo $C_CYAN"====== START AST DIFF TESTS ======"$C_CLEAR
if ! `env | grep -q ^LAST_ONLY=`
then

    diff_test features_ast 01_empty
    diff_test features_ast 10_simple_command
    diff_test features_ast 11_simple_command_empty_lines
    diff_test features_ast 12_simple_command_no_newline
    diff_test features_ast 20_subshell
    diff_test features_ast 30_redir
    diff_test features_ast 40_assignment
    diff_test features_ast 50_if_clause
    # diff_test features_ast ast_list2
    # diff_test features_ast ast_list3
    # diff_test features_ast ast_list4
    # diff_test features ast_echo
    # diff_test features ast_list
    # diff_test features ast_andor_seq
    # diff_test features ast_andor_item
    # diff_test features ast_subshell
    # diff_test features ast_subshell_err

    # for CASE_PATH in $TESTS_ROOT_PATH/*; do
    #     if [ -d "${CASE_PATH}" ]; then
    #         for TEST_PATH in $CASE_PATH/*; do
    #             if [ -d "${TEST_PATH}" ]; then
    #                 diff_test `basename $CASE_PATH` `basename $TEST_PATH`
    #             fi
    #         done
    #     fi
    # done

else

    diff_test features_ast ast_list

fi
echo $C_CYAN"======  END TESTS  ======"$C_CLEAR

exit $exit_status
