trap "echo sig1" 1
trap "echo sig2" 2
trap "echo sig3" 3
trap "echo sig30" 30
trap "echo sig31" 31
trap

PID=`bash -c 'echo $PPID'`
kHUP -HUP $PID
kHUP -1 $PID
kHUP -2 $PID
kHUP -3 $PID
kHUP -30 $PID
kHUP -31 $PID
