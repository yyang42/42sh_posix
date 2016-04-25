. $TESTS_ROOT/setup.sh

send_line "echo abc > $TEST_STDOUT && echo abc"

. $TESTS_ROOT/teardown.sh
