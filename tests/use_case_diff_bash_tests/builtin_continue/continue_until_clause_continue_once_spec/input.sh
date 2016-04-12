counter=0
until false
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
