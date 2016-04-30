set -m
sleep 0.5 && echo "background msg1" &
sleep 0.3 && echo "background msg2" &
sleep 0.1
echo "before fg"
fg > /tmp/builtin_fg_test_file && cat -e /tmp/builtin_fg_test_file | sed 's/ &//g'
echo "after fg"
wait
