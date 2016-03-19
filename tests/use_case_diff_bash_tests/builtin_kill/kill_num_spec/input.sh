(
	sleep 0.5 &
	pid=`jobs -p`
	sleep 0.6 &
	jobs
	/bin/kill $pid
	sleep 0.1

	jobs -l
) 2> /tmp/builtin_jobs_result_out 1> /tmp/builtin_jobs_result_err
cat /tmp/builtin_jobs_result_out /tmp/builtin_jobs_result_err | sed -E 's/[0-9]+/X/g' | sed 's/ &//g'
