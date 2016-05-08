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
    input_file=$testcase_path/input.sh
    cp $input_file /tmp/input.sh

    if ! [ -z ${CI+x} ] && test "${testcase#*_noci_spec}" != "$testcase"; then
        echo "skip no ci    $input_file"
        return
    fi
    mkdir -p $testcase_tmp
    rm -f $testcase_tmp/*
    export TESTED_SHELL
    TESTED_SHELL=$RENDU_PATH/42sh
    $RENDU_PATH/42sh /tmp/input.sh > $testcase_tmp_stdout 2> $testcase_tmp_stderr
    echo "exit_code: $?" >> $testcase_tmp_stdout
    if [ ! -f $testcase_path/expected_stdout ] || [ ! -f $testcase_path/expected_stderr ]; then
        TESTED_SHELL='bash --posix'
        bash --posix /tmp/input.sh > $testcase_tmp_bash_stdout 2> $testcase_tmp_bash_stderr
        echo "exit_code: $?" >> $testcase_tmp_bash_stdout
    fi
    if [ -f $testcase_path/expected_stdout ]; then
        expected_stdout_file=$testcase_path/expected_stdout
    else
        expected_stdout_file=$testcase_tmp_bash_stdout
    fi
    if [ -f $testcase_path/expected_stderr ]; then
        expected_stderr_file=$testcase_path/expected_stderr
    else
        expected_stderr_file=$testcase_tmp_bash_stderr
    fi
    diff $expected_stdout_file $testcase_tmp_stdout
    stdout_res="$?"
    diff $expected_stderr_file $testcase_tmp_stderr
    stdout_err="$?"

    print_result "$stdout_res" stdout
    print_result "$stdout_err" stderr
    echo "./42sh tests/use_case_diff_bash_tests/$testsuite/$testcase/input.sh"
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
