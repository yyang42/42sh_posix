(
	sleep 0.2 &
	pid=`jobs -p`
	sleep 0.3 &
	jobs
	/bin/kill $pid
	sleep 0.2
	jobs -l
) > /tmp/test_kill_stdout 2> /tmp/test_kill_stderr
cat /tmp/test_kill_stdout /tmp/test_kill_stderr | sed -E 's/[0-9]+/X/g' | sed -e 's/.*input\.sh/CMD_PATH/g' | sed -e 's/ &//g' | sort | cat -e
