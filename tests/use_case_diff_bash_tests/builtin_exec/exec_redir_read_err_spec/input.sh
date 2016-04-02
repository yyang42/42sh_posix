echo "the answer is 42" > /tmp/test_builtin_exec_read_file
exec 42< /tmp/test_builtin_exec_read_file
cat <&42
exec 42<&-
cat <&42
echo "Should not write the following line:" >&2
echo "Can't write this" >&42
