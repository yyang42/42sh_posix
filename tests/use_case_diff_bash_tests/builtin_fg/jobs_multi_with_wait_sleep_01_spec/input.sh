set -m
sleep 0.5 && echo "background msg1" &
sleep 0.3 && echo "background msg2" &
sleep 0.1 && echo "background msg3" &
sleep 0.2 && echo "background msg4" &
echo "before fg1"
fg > /tmp/builtin_fg_test_file && cat -e /tmp/builtin_fg_test_file | sed 's/ &//g'
echo "after fg1"
sleep 0.1
echo "before fg2"
fg > /tmp/builtin_fg_test_file && cat -e /tmp/builtin_fg_test_file | sed 's/ &//g'
echo "after fg2"
echo "before fg3"
fg > /tmp/builtin_fg_test_file && cat -e /tmp/builtin_fg_test_file | sed 's/ &//g'
echo "after fg3"
wait
