export myvar=9
until echo $myvar | cat | grep 99999 ; do
	echo $myvar
	myvar=9$myvar
done
