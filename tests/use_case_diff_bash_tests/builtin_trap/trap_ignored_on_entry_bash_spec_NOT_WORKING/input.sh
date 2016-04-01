trap '' HUP INT USR1 USR2
trap 'echo USR2msg' USR2
echo 'trap "echo abc" USR1 INT HUP USR2 && trap | sort' > /tmp/trap_test.sh
bash --posix /tmp/trap_test.sh
