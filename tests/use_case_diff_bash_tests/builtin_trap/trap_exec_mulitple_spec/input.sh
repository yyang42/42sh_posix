trap "echo sig1" 1
trap "echo sig2" 2
trap "echo sig3" 3
trap "echo sigHUP" HUP
trap "echo sigINT" INT
trap

PID=`bash -c 'echo $PPID'`
kill -HUP $PID
kill -1 $PID
kill -2 $PID
kill -3 $PID
kill -HUP $PID
kill -INT $PID
