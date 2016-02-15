# subshell
a=b
fn () (
	echo $a
	a=c
)
fn
echo $a
# brace group
a=b
fn () {
	echo $a
	a=c
}
fn
echo $a
