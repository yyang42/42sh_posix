trap "uname" HUP
echo "===1"
trap | sort
save_traps=$(trap)
trap - HUP
echo "===2"
trap | sort
eval $save_traps
echo "===3"
trap | sort
