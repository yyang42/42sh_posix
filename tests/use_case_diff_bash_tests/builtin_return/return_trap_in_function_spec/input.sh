foo ()
{
	PID=$$
	trap 'return' USR1
	echo 'Before kill'
	kill -USR1 $PID
	echo 'After kill'
}
foo
