#!/bin/sh

C_CYAN="\033[36;1m"
C_GREEN="\033[32;1m"
C_RED="\033[31;1m"
C_CLEAR="\033[0m"

RENDU_PATH="`pwd`"
TESTS_ROOT="${RENDU_PATH}/tests/line_edition_tests"
PRINT="/usr/bin/printf"

make
mkdir -p /tmp/bin
cp -f ${RENDU_PATH}/42sh /tmp/bin/
cp -f `command -v bash` /tmp/bin/bash

exit_status=0
count_success=0
count_failure=0

if [ "$?" -ne "0" ]; then
	exit 1
fi

print_result () {
	if [ $1 -eq 0 ]; then
		${PRINT} "${C_GREEN}${2}${C_CLEAR} "
		count_success=$((count_success+1))
	else
		${PRINT} "${C_RED}${2}${C_CLEAR} "
		count_failure=$((count_failure+1))
		exit_status=1
	fi
}

diff_test () {
	testcase_tmp="${1}/.tmp"
	testcase_tmp_stdout="${1}/.tmp/actual_stdout"
	testcase_tmp_stderr="${1}/.tmp/.actual_stderr"
	testcase_tmp_bash_stdout="${1}/.tmp/expected_stdout"
	testcase_tmp_bash_stderr="${1}/.tmp/.expected_stderr"
	mkdir -p $testcase_tmp
	export __STDERR_FILE__=${testcase_tmp_bash_stderr}
	${PRINT} "`cat ${1}/input`" | /tmp/bin/bash --posix -i > ${testcase_tmp_bash_stdout} 2> ${testcase_tmp_bash_stderr}
	echo "exit status: $?" >> ${testcase_tmp_bash_stdout}
	export __STDERR_FILE__=${testcase_tmp_stderr}
	${PRINT} "`cat ${1}/input`" | /tmp/bin/42sh -i > ${testcase_tmp_stdout} 2> ${testcase_tmp_stderr}
	echo "exit status: $?" >> ${testcase_tmp_stdout}

	if [ -f "${1}/expected_stdout" ]; then
		testcase_tmp_bash_stdout="${1}/expected_stdout"
	fi
	diff $testcase_tmp_bash_stdout $testcase_tmp_stdout
	stdout_res="$?"

	print_result "$stdout_res" stdout
	${PRINT} "tests/line_edition_tests/%s/%s/input\n" `basename $CASE_PATH` `basename $TEST_PATH`
}

${PRINT} "=========================== START LINE EDITION TESTS ===========================\n"

for CASE_PATH in $TESTS_ROOT/${PATTERN:-*}; do
	if [ -d "${CASE_PATH}" ]; then
		for TEST_PATH in $CASE_PATH/*_spec; do
			if [ -d "${TEST_PATH}" ]; then
				diff_test $TEST_PATH
			fi
		done
	fi
done

if [ $count_failure -gt 0 ]; then
    echo "$C_RED\c"
else
    echo "$C_GREEN\c"
fi

${PRINT} "=========================== %4i failed, %4i passed ===========================\n" ${count_failure} ${count_success}
echo "$C_CLEAR\c"

exit $exit_status
