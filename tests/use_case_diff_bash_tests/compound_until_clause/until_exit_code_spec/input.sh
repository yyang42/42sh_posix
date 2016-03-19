export myvar=9
until [ $myvar -gt 9999  ]; do
	myvar=9$myvar
	echo myvar: $myvar
	(exit 42)
done
