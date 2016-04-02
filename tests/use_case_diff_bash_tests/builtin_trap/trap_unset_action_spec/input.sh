PID=`bash -c 'echo $PPID'`
trap "echo AAA" HUP
trap "echo BBB" INT
trap "echo CCC" QUIT
trap
kill -INT $PID
trap - INT QUIT
trap
trap - HUP
trap
trap - HUP
trap
