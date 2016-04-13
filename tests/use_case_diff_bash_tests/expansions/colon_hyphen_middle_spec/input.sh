x=pouet
echo ${x:- \a $x 'b' "c"}
unset x
echo ${x:- \a $x 'b' "c"}
echo "${x:- "a"}"
