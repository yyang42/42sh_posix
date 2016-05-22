echo "one cat"
echo abcde | $TESTED_SHELL -c 'cat -e'
echo "many cats"
echo abcde | $TESTED_SHELL -c 'cat | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e'
