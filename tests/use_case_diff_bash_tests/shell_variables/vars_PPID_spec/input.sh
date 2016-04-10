echo $PPID | grep -qE '^\d+$'
echo grep_status $?

parent_ppid=$PPID
child_ppid=`echo $PPID`
if [ $parent_ppid = $child_ppid ]; then
  	echo "match"
else
	echo "not match"
fi


echo "PPID is readonly, this should fail"
PPID=123
