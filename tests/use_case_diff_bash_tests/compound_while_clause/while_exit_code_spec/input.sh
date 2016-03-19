export myvar=9
while [ $myvar -lt 999999  ]; do
	myvar=9$myvar
	echo myvar: $myvar
	(exit 42)
done
