alias aa=bb
echo ">> 1"
alias
echo ">> 2"
env alias 2>&1 | sed 's/No such file or directory/command not found/g'
echo ">> 3"
