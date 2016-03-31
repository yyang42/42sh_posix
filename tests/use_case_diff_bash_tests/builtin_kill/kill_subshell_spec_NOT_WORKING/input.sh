(
	PID=`bash -c 'echo $PPID'`
	kill -TERM $PID
	wait $PID 2>/tmp/test_kill_stderr
) &> /tmp/test_kill_stderr
cat /tmp/test_kill_stderr | grep -q "Terminated: 15"
