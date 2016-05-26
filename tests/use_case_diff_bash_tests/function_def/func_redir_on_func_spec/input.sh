foo ()
{
	echo abc
	echo 123
} > /tmp/function_def_tmp_file
foo
cat /tmp/function_def_tmp_file
