echo ${x- \a $x 'b' "c"}
echo ${x- "a"}
echo ${x-aaa`echo fifo`bbb}
echo ${x-$((1+1))$(echo pouet)`echo foo`}

echo "${x- \a $x 'b' "c"}"
echo "${x- "a"}"
echo "${x-aaa`echo fifo`bbb}"
echo "${x-$((1+1))$(echo pouet)`echo foo`}"
