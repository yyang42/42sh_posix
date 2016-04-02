trap "echo abc" 1 2 3
trap
save_traps=$(trap)
eval "$save_traps"

# trap "echo abc" 1 2 3
# trap
# save_traps=$(trap)
# eval "$save_traps"
