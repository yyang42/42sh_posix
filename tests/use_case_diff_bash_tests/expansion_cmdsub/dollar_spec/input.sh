echo $( i=0;
while [ $i -lt 25 ]
do
	echo "  $((save=i, i+=1, save))  "
done )

echo $( echo $( echo $( echo $( echo abc ) ) ) )
echo "$( echo $( echo $( echo $( echo abc ) ) ) )"
echo $( echo $( echo $( echo "$( echo "abc" )" ) ) )
echo $( echo "$( echo $( echo "$( echo abc )" ) )" )
echo "$( echo "$( echo "$( echo "$( echo "abc" )" )" )" )"

echo $( python -c 'print "a"+"\n"*30' )
echo "$( python -c 'print "a"+"\n"*30' )"

echo $( echo "''"'""\\``$$(())[][]' )
echo "$( echo "''"'""\\``$$(())[][]' )"
