#!/bin/sh

C_CYAN="\033[36;1m"
C_GREEN="\033[32;1m"
C_RED="\033[31;1m"
C_CLEAR="\033[0m"

RENDU_PATH="`pwd`"
TESTS_ROOT_PATH="$RENDU_PATH/tests/ast_diff_tests"
LOGFILE=$RENDU_PATH/.valgrind.log
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

    if `env | grep -q ^LEAK_TEST=`
    then
        valgrind --leak-check=full --log-file="$LOGFILE" $RENDU_PATH/42sh -z $testcase_path/input.sh
        if grep -q "definitely lost: 0 bytes in 0 blocks" $LOGFILE || grep -q "in use at exit: 0 bytes in 0 blocks" $LOGFILE
        then
            echo $C_GREEN"No Leaks $testcase_path"$C_CLEAR
        else
            cat $LOGFILE
            echo   $C_RED"=== Leaks test fail      ==="$C_CLEAR
            exit 1
        fi
        if grep -q "Invalid read"; then
            cat $LOGFILE
            echo   $C_RED"=== Leaks test fail      ==="$C_CLEAR
            exit 1
        fi
    else
        diff $testcase_path/expected_stdout $testcase_tmp_stdout
        print_result "$?"
        echo " stdout $testsuite/$testcase"
        diff $testcase_path/expected_stderr $testcase_tmp_stderr
        print_result "$?"
        echo " stderr $1/$2"
    fi
}

echo $C_CYAN"====== START AST TESTS ======"$C_CLEAR
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
