trap "foo () { echo foo_called; } ; foo" HUP
trap
kill -HUP $$
