trap aa 32 42 -n -- 1 2 3 2> /tmp/test_trap_stderr
cat /tmp/test_trap_stderr | sed -e 's/.*input\.sh/CMD_PATH/g'
