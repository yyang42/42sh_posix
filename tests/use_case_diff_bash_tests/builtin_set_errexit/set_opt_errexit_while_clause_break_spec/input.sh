set -e
echo init
export item=a
while ! [ $item = aaaa ]
do
	echo $item 1
	item=a$item
	(exit 42)
	echo $item 2
done
echo should not exec
