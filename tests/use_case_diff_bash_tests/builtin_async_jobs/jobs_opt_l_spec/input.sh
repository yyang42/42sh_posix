sleep 0.01 && exit 21 &> /dev/null &
sleep 0.02 && exit 42 &> /dev/null &
sleep 0.05 && exit 84 &> /dev/null &
# sleep 10 && echo 3 &> /dev/null &
# sleep 10 && echo 4 &> /dev/null &
sleep 0.03
# jobs -3
# | sed 's/>\&\/dev/\&> \/dev/g' | sed 's/[[:digit:]]/9/g'

jobs -l > /tmp/builtin_jobs_result
cat /tmp/builtin_jobs_result | sed 's/>\&\/dev/\&> \/dev/g' | sed -E 's/^\[[0-9]\]+(\+|-| ) [0-9]+ //g'  | sed -E 's/ &$//g'
#
