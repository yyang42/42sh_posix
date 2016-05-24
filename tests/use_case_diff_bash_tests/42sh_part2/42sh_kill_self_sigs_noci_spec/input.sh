echo abc

# : > /tmp/42sh_test_log
for i in `seq 1 15` 16 `seq 19 20` `seq 23 31`
do
	printf "sig %s\n" $i
	echo "kill -$i" '$$' > /tmp/42sh_script
	($TESTED_SHELL -c "$(cat /tmp/42sh_script)")
	echo "status $?"
done

# echo "/tmp/42sh_test_log"  >> /tmp/42sh_test_log
# cat /tmp/42sh_test_log
