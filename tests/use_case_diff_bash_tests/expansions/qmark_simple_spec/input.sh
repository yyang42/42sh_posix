foobar=posix
echo ${foobar?}
foobar=
echo ${foobar?}
unset foobar
(
	echo ${foobar?}
) &> /tmp/test_stderr
err=$(cat /tmp/test_stderr)
echo ${err##*foobar}
