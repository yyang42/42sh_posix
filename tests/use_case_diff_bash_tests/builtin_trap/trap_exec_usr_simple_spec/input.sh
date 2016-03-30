trap "echo abc" HUP
trap
kill -HUP `bash -c 'echo $PPID'`
