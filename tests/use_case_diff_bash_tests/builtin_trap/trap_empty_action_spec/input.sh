trap "" HUP
trap "   " INT
trap
kill -HUP `bash -c 'echo $PPID'`
kill -INT `bash -c 'echo $PPID'`
