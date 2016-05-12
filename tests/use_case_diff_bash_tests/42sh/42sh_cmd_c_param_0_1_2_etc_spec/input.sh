$TESTED_SHELL -c 'echo $0-$1-$2-$3; echo $@' aa bb cc
$TESTED_SHELL -c 'echo $0-$1-$2-$3; echo $@' | sed 's/bash/42sh/'
echo "abc" | $TESTED_SHELL -c 'echo 123'
