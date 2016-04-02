# # rm /tmp/test_builtin_exec_write_file
# touch /tmp/test_builtin_exec_write_file
exec 42> /tmp/test_builtin_exec_write_file
echo "the answer is 42" >&42
# # echo "================"
cat /tmp/test_builtin_exec_write_file
exec 42<&-
