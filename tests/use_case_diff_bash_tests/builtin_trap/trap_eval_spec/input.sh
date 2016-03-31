trap "uname" HUP
echo "===1"
trap
save_traps=$(trap)
trap - HUP
echo "===2"
trap
eval $save_traps
echo "===3"
trap
