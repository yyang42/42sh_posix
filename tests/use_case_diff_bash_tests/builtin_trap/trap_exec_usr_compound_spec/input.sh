trap "foo () { echo foo_called; } ; foo" 30
trap
kill -30 `bash -c 'echo $PPID'`
