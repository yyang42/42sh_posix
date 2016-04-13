counter=0
while true
do
	echo "start" $counter
	counter=$((counter+1))
	if [ $counter -gt 5 ]
	then
		break
	fi
	if [ $counter -gt 3 ]
	then
		continue
	fi
	echo "end" $counter
done
