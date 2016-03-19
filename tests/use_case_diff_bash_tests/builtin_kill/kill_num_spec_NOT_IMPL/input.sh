(
	sleep 10 &
	pid=`jobs -p`
	sleep 11 &
	# jobs
	# kill -TSTP $pid
	kill $pid
	# echo abc
	sleep 0.1
	jobs
)
