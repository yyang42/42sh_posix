trap "foo () { echo foo_called; } ; foo" HUP
trap
kill -HUP `bash -c 'echo $PPID'`
