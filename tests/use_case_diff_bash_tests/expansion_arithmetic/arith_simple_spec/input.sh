echo $(())
echo $((1))
echo $((-1))
echo $((1+1))
echo "$(())"
echo "$((1))"
echo "$((-1))"
echo "$((1+1))"

echo $((1))$((2))$((3))

a=1+1

echo $(($a))

set 1 + 1
echo $(($*))
echo $(($@))
