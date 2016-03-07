export myvar=9
while !echo $myvar | cat | grep 999 ; do
	myvar=9$myvar
done
