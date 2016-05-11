$TESTED_SHELL -i -c 'echo abc' 2> /tmp/42sh_test_file
cat /tmp/42sh_test_file| sed 's/bash/42sh/'
