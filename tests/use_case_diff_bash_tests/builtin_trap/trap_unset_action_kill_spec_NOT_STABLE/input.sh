(
	PID=`bash -c 'echo $PPID'`
	trap "echo AAA" TERM
	kill -TERM $PID
	trap
	trap - TERM
	kill -TERM $PID
	echo "should not exec"
)
