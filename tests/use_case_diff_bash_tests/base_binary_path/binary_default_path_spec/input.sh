(
	PATH=''
	ls
	echo 'abc' | cat -e
	ls / | grep etc
) 2> /tmp/binary_default_path_spec_tmp

cat /tmp/binary_default_path_spec_tmp | sed 's/No such file or directory/command not found/g'
