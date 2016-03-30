trap "echo sig1" 1
trap "echo sig2" 2
trap "echo sig3" 3
trap "echo sig30" 30
trap "echo sig31" 31
trap

PID=`bash -c 'echo $PPID'`
kill -HUP $PID
kill -1 $PID
kill -2 $PID
kill -3 $PID
kill -30 $PID
kill -31 $PID
