counter=0
until false
do
	echo "start" $counter
	counter=`echo $counter + 1 | bc`
	if [ $counter -gt 5 ]
	then
		break  # Skip entire rest of loop.
	fi
	echo "end" $counter
done
