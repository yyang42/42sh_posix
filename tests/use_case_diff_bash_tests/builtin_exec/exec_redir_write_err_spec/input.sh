exec 42> /tmp/test_builtin_exec_write_file
echo "the answer is 42" >&42
echo "================1"
cat /tmp/test_builtin_exec_write_file
echo "================2"
echo "Should not be able to read:" >&2
cat <&42
exec 42<&-

