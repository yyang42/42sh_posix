. $TESTS_ROOT/setup.sh

send_line "echo abc > $TEST_STDOUT"
send_line "echo abc | cat -e > $TEST_STDOUT"

. $TESTS_ROOT/teardown.sh
