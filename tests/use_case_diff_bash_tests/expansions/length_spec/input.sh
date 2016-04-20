echo ${#foo}
foo=`python -c 'print "lal"*100'`
echo ${#foo}
set a b c
echo ${#*}
IFS=pouet
echo "${#*}"
