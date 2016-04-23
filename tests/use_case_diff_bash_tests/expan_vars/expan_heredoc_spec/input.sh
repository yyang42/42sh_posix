export myvar=123
set foo bar baz
cat << EOF
$myvar
'aaa'
"bbb"
"bb$myvar"
"$myvar"
# "bb$myvar"
$( echo $(echo $(echo bbb) 123) bbc )
$( echo bbc )
$((10+23))
echo abc
$?
`echo 123`
`echo 123 | cat -e`
`echo 123 `echo abc``
`echo aaa $(echo bbb $( echo ccc $(echo ddd | wc) ) ) `
$(pwd)
$(echo acb | cat | cat -e | cat | cat -e | cat | cat -e | cat | cat -e | cat | cat -e | cat | cat -e | cat | cat -e | wc)
echo "${1}$2${3}"
EOF
# 'aa$myvar'
