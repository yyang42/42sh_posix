trap "" HUP
trap
kill -HUP `bash -c 'echo $PPID'`
