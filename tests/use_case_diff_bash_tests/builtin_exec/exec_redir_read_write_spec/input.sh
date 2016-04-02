echo "the answer is 42" > /tmp/test_builtin_exec_read_file
exec 42<> /tmp/test_builtin_exec_read_file
cat <&42
echo "the answer is not 43" >&42
cat <&42
exec 42<&-
