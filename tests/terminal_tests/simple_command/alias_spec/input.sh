. $TESTS_ROOT/setup.sh

send_line "alias aa='echo 123'"
send_line "aa > $TEST_STDOUT"

. $TESTS_ROOT/teardown.sh
