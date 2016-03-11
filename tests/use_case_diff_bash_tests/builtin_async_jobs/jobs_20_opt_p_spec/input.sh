sleep 0.020 && echo 1 &> /dev/null &
sleep 0.020 && echo 2 &> /dev/null &
sleep 0.020 && echo 3 &> /dev/null &
sleep 0.020 && echo 4 &> /dev/null &

# jobs -p | sed 's/>\&\/dev/\&> \/dev/g' | sed 's/[[:digit:]]/9/g'

jobs -p > /tmp/builtin_jobs_result
cat /tmp/builtin_jobs_result | sed 's/>\&\/dev/\&> \/dev/g' | sed -E 's/[0-9]+//g' | sed -E 's/ &$//g'
