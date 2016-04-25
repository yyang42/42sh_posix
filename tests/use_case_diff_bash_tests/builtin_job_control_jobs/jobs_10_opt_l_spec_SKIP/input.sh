{
	sleep 0.01 && exit 21 &> /dev/null &
	sleep 0.02 && exit 42 &> /dev/null &
	sleep 0.20 && exit 84 &> /dev/null &
	sleep 0.15

	jobs -l > /tmp/builtin_jobs_result
} 2> /dev/null
cat /tmp/builtin_jobs_result  | sed 's/> \//>\//g' | sed 's/\>\&/\&\>/g' | sed -E 's/^\[[0-9]\]+(\+|-| ) +[0-9]+ //g'  | sed -E 's/ &$//g'
