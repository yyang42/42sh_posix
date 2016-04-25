. $TESTS_ROOT_PATH/setup.sh

send_line "$TEST_SHELL"
send_line "alias aa='echo 123'"
send_line "aa > $TEST_STDOUT"
send_line "exit 42"
