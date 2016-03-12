sleep 0.010 && echo 1 &> /dev/null &

mypid=`jobs -p`
echo $mypid

# jobs > /tmp/builtin_jobs_result
# cat /tmp/builtin_jobs_result | sed 's/>\&\/dev/\&> \/dev/g' | sed -E 's/^\[[0-9]\]+(\+|-| ) [0-9]+ //g'  | sed -E 's/ &$//g'
