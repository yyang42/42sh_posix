trap "echo abc" 1 2 3
trap
save_traps=$(trap)
eval "$save_traps"
trap - 1 2
echo "=======1"
trap | sort
echo "=======2"
eval "$save_traps"
echo "=======3"
trap | sort
