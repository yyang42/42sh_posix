set -m
sleep 0.5 && echo "background msg" &
echo "before fg"
fg > /tmp/builtin_fg_test_file
cat -e /tmp/builtin_fg_test_file | sed 's/ &//g'
echo "after fg"
