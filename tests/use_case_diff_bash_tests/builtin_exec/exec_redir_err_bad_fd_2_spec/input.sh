exec 42> /tmp/test_builtin_exec_write_file
echo message1 >&42
cat /tmp/test_builtin_exec_write_file
exec 42<&-
echo message2 >&42
cat /tmp/test_builtin_exec_write_file
