echo $- | grep a &> /dev/null
echo status $?
echo ${-} | grep a &> /dev/null
echo status $?
set -a
echo $- | grep a &> /dev/null
echo status $?
echo ${-} | grep a &> /dev/null
echo status $?
