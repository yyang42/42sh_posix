(
	unset PATH
	ls /tmp
) 2> /tmp/binary_default_path_spec_tmp

cat /tmp/binary_default_path_spec_tmp | sed 's:env: ls: No such file or directory:/tmp/bin/42sh: line 1: ls: command not found:g'
