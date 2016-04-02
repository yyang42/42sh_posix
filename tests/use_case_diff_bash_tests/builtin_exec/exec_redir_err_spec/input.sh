# exec 42> /tmp/test_builtin_exec_write_file
# # echo abc >&42
# # cat /tmp/test_builtin_exec_write_file
# exec 42>&-
echo abc >&42
