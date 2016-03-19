(
	sleep 0.1 &
	pid=`jobs -p`
	sleep 0.2 &
	jobs
	/bin/kill $pid
	sleep 0.1
	jobs -l
) 2>&1 | sed -E 's/[0-9]+/X/g' | sed -e 's/.*input\.sh/CMD_PATH/g' | sed -e 's/ &//g' | sort
