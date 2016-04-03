set -e
echo init
export item=a
until [ $item = aaaa ]
do
	echo $item
	item=a$item
done
echo should exec
