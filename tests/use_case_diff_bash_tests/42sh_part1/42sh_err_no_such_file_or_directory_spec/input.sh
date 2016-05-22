$TESTED_SHELL /tmp/not_exist  2> /tmp/42sh_test_file | sed 's/bash/42sh/'
cat /tmp/42sh_test_file | sed 's/bash/42sh/'

