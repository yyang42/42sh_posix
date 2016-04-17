set pif paf pouf

myfn () {
	echo $1 $2 $3
}
myfnquoted () {
	echo "$1 $2 $3"
}

foo=abc
bar=def
myfn foo bar baz
myfn $3 $2 $1
myfn $foo $bar $baz
myfn $foo $baz $bar
myfnquoted foo bar baz
myfnquoted $3 $2 $1
myfnquoted $foo $bar $baz
myfnquoted $foo $baz $bar
