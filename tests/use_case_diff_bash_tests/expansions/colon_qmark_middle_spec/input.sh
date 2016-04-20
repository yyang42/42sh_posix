foobar=
(
	echo ${foobar:?pif paf   pouf}
) &> /tmp/test_stderr
err=$(cat /tmp/test_stderr)
echo ${err##*foobar}
