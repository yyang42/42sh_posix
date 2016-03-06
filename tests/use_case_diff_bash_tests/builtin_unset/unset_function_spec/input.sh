foo () {
	echo foo_called
}
bar () {
	echo bar_called
}
foo
bar
unset -f foo
unset bar
foo
bar
