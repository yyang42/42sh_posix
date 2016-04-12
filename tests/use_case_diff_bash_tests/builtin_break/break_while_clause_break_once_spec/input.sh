counter=0
while true
do
	echo "start" $counter
	counter=$((counter+1))
	echo $counter
	if [ $counter -gt 5 ]
	then
		break
	fi
	echo "end" $counter
done
