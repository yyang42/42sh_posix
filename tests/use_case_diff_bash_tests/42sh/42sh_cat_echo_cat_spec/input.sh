echo "one cat"
echo abcde | $TESTED_SHELL -c 'cat -e; echo 123; cat -e'
