trap '' HUP INT USR1 USR2
trap 'echo USR2msg' USR2
trap
bash -c 'trap "echo abc" USR1 INT HUP  && trap | sort'
bash -c 'trap "echo USR2msgOverriden" USR2 && trap | sort'

./42sh -c 'trap "echo abc" USR1 INT HUP && trap | sort'
./42sh -c 'trap "echo USR2msgOverriden" USR2 && trap | sort'
