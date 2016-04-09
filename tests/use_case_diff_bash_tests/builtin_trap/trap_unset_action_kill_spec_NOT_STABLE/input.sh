(
	PID=$$
	trap "echo AAA" TERM
	kill -TERM $PID
	echo "should not exec"
)
