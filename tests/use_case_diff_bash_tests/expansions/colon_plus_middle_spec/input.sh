set a b c
foo=bar
echo ${x:+$(ls)$@$1$2 $3`echo aa bb`$foo}
echo ${lelel:+~}

echo "${x:+$(ls)$@$1$2 $3`echo aa bb`$foo}"
echo "${lelel:+~}"
