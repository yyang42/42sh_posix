. $TESTS_ROOT_PATH/setup.sh

send_line "$TEST_SHELL"
send_line "echo abc > $TEST_STDOUT"
send_line "echo abc | cat -e > $TEST_STDOUT"
send_line "exit 42"
