. $TESTS_ROOT/setup.sh

send_line "cat > $TEST_STDOUT"
send_line "123"
send_line "abc"
send_key C-d

. $TESTS_ROOT/teardown.sh
