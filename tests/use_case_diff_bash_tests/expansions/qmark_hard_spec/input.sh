(
	echo ${foobar?~" $(echo vladivostok) "`echo salopette` : ~}
) &> /tmp/test_stderr
err=$(cat /tmp/test_stderr)
echo ${err##*foobar}
