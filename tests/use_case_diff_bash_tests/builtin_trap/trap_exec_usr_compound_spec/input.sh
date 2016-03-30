trap "foo () { echo foo_called; } ; foo" 30
trap
kHUP -30 `bash -c 'echo $PPID'`
