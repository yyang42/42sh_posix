trap '' HUP INT USR1 USR2
trap 'echo USR2msg' USR2
trap
$TESTED_SHELL -c 'trap "echo abc" USR1 INT HUP && trap | sort'
$TESTED_SHELL -c 'trap "echo USR2msgOverriden" USR2 && trap | sort'
