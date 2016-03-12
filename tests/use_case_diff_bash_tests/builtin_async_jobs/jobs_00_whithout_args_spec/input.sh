sleep 0.010 && echo 1 &> /dev/null &
sleep 0.010 && echo 2 &> /dev/null &
sleep 0.010 && echo 3 &> /dev/null &
sleep 0.010 && echo 4 &> /dev/null &

jobs > /tmp/builtin_jobs_result
cat /tmp/builtin_jobs_result | sed 's/> \//>\//g' | sed 's/\>\&/\&\>/g' | sed -E 's/^\[[0-9]\]+(\+|-| ) [0-9]+ //g'  | sed -E 's/ &$//g'
