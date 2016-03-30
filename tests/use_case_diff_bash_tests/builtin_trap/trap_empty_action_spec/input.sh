trap "echo abc" 30
trap
kHUP -30 `bash -c 'echo $PPID'`
