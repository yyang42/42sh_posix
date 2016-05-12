echo "abc (" > /tmp/42sh_test.sh
/tmp/bin/42sh /tmp/42sh_test.sh 2> /tmp/42sh_test_stderr
cat /tmp/42sh_test_stderr
