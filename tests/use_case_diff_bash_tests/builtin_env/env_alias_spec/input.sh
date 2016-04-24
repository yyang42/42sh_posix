alias aa=bb
echo ">> 1"
alias
echo ">> 2"
env alias 2>&1 | sed 's/env:/42sh: line 1:/g'
echo ">> 3"
