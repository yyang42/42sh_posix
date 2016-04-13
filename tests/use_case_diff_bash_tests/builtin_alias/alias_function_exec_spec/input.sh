
alias echoabc="echo 11"

foo ()
{
	echoabc aa
}
alias echoabc="echo 22"

foo2 ()
{
	echoabc bb
}
foo
foo2
