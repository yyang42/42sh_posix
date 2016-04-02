PID=`bash -c 'echo $PPID'`; trap 'return' USR1; echo 'Before kill'; kill -USR1 $PID; echo 'After kill'
