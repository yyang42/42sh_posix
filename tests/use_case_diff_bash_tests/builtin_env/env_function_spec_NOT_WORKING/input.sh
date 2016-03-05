plus1 () { echo $(($1 + 1)); }

echo $(plus1 8)

export -f plus1

bash -c 'echo $(plus1 3 )'
