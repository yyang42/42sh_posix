echo "line 1"
(
	PID=`bash -c 'echo $PPID'`
	echo "before kill"
	kill -TERM $PID
	echo "after kill"
) &> /tmp/test_subshell_out

echo "======"
cat /tmp/test_subshell_out
