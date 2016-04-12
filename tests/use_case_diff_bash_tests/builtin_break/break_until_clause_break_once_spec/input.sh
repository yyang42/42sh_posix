counter=0
until false
do
	echo "start" $counter
	counter=$((counter+1))
	echo counter $counter
	if [ $counter -gt 5 ]
	then
		break
	fi
	echo "end" $counter
done
