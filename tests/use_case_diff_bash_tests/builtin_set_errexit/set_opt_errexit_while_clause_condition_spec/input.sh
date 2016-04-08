set -e
echo init
export item=a
while ! [ $item = aaaa ]
do
	echo $item
	item=a$item
done
echo should exec
