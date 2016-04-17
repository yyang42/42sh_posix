printf 'echo abc\nfor i in aa bb\ndo\necho $i\ndone\n' > /tmp/test_set_verbose
set -v ; . /tmp/test_set_verbose
