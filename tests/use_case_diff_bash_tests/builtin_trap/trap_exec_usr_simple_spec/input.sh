trap "echo abc" 30
trap
kill -30 `bash -c 'echo $PPID'`
