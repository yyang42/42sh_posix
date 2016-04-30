set -m
sleep 0.2 && echo "background msg3" &
sleep 0.3 && echo "background msg4" &
sleep 0.1
fg %2 > /tmp/builtin_fg_test_file && cat -e /tmp/builtin_fg_test_file | sed 's/ &//g'
fg %1 > /tmp/builtin_fg_test_file && cat -e /tmp/builtin_fg_test_file | sed 's/ &//g'
wait
