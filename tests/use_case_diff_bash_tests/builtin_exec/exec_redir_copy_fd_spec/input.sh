exec 42> /tmp/test_builtin_exec_write_file
exec 43<&42
echo "the answer is 42" >&42
echo "the answer is not 43" >&43
echo "================"
cat /tmp/test_builtin_exec_write_file
exec 42<&- 43<&-
