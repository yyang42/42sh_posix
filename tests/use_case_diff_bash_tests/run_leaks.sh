#!/bin/sh

C_CYAN="\033[36;1m"
C_GREEN="\033[32;1m"
C_RED="\033[31;1m"
C_CLEAR="\033[0m"

RENDU_PATH="`pwd`"
TESTS_ROOT="$RENDU_PATH/tests/use_case_diff_bash_tests/"

exit_status=0
count_success=0
count_failure=0

make
mkdir -p /tmp/bin
cp $RENDU_PATH/42sh /tmp/bin/
cp -f `which bash` /tmp/bin/bash

if [ "$?" -ne "0" ]; then
    exit 1
fi

print_result ()
{
    if [ $1 -eq 0 ]
    then
        /usr/bin/printf $C_GREEN"$2"$C_CLEAR"\c"
        count_success=$((count_success+1))
    else
        /usr/bin/printf $C_RED"$2"$C_CLEAR"\c"
        count_failure=$((count_failure+1))
        exit_status=1
    fi
    /usr/bin/printf " \c"
}

diff_test ()
{
    testsuite=$1
    testcase=$2
    testcase_path="$TESTS_ROOT/$testsuite/$testcase"
    testcase_tmp="$testcase_path/.tmp"
    testcase_tmp_stdout="$testcase_tmp/actual_stdout"
    testcase_tmp_stderr="$testcase_tmp/actual_stderr"
    testcase_tmp_bash_stdout="$testcase_tmp/expected_stdout"
    testcase_tmp_bash_stderr="$testcase_tmp/expected_stderr"

    if ! [ -z ${CI+x} ] && test "${testcase#*_noci_spec}" != "$testcase"; then
        echo "skip no ci    $input_file"
        return
    fi
    valgrind  --gen-suppressions=all --num-callers=50 ./42sh $testcase_path/input.sh
    status=$?
    if [ $status -ne 0 ]; then
        echo $status
        exit ;
    fi
}

/usr/bin/printf "============================ START AST DIFF TESTS ==========================\n"
for CASE_PATH in $TESTS_ROOT/${PATTERN:-*}; do
    if [ -d "${CASE_PATH}" ]; then
        for TEST_PATH in $CASE_PATH/*_spec; do
            if [ -d "${TEST_PATH}" ]; then
                diff_test `basename $CASE_PATH` `basename $TEST_PATH`
            fi
        done
    fi
done

if [ $count_failure -gt 0 ]; then
    echo "$C_RED\c"
else
    echo "$C_GREEN\c"
fi
echo "============================ $count_failure failed, $count_success passed ============================"
echo "$C_CLEAR\c"
# /usr/bin/printf $C_CYAN"======  END TESTS  ==============="$C_CLEAR"\n"

exit $exit_status
