echo "" > /tmp/test_builtin_exec_executable
cat -e /tmp/test_builtin_exec_executable
$TESTED_SHELL -c 'exec /tmp/test_builtin_exec_executable'
