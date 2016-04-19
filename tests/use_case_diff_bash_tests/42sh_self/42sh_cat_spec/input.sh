echo "one cat"
echo abcde | ./42sh -c 'cat -e'
echo "many cats"
echo abcde | ./42sh -c 'cat | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e | cat -e'
