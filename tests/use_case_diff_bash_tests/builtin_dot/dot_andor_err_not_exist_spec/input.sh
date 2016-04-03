. /tmp/file_not_exist && echo "should not exec"
. /tmp/file_not_exist || echo "should exec"
