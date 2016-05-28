#!/bin/sh

logfile=valgrind.log
rm $logfile

for file in `find ./tests/use_case_diff_bash_tests -name 'input.sh'`;
do
	valgrind --gen-suppressions=all --num-callers=50 ./42sh $file 2>&1 | tee -a $logfile ;
done
