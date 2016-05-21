set -x
echo PS4: $PS4
echo abc
PS4=AB
echo 123
unset PS4
echo 456
a=b
for i in a b
do
	echo abc
done
