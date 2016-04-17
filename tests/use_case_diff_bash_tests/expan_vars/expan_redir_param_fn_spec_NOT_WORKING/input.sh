myvar=123
myfn () {
	export myvar=$myvar-$myvar
	echo abc > /tmp/test_expan_redir_param_$myvar
	cat /tmp/test_expan_redir_param_123
	cat /tmp/test_expan_redir_param_$myvar
}
myfn 1
myfn 2
myfn 3
