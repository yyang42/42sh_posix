. $TESTS_ROOT_PATH/setup.sh

send_line "$TEST_SHELL"
send_line "echo abc > $TEST_STDOUT && echo abc"
send_line "exit 42"
