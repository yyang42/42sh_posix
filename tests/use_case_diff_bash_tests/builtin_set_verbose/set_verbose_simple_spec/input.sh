printf 'echo abc\necho 123\n' > /tmp/test_set_verbose
set -v ; . /tmp/test_set_verbose
