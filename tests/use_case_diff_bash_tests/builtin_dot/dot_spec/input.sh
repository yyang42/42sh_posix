echo "foo=hello bar=world" > foobar
. ./foobar
echo $foo $bar
rm foobar
echo "foo=tata bar=toto" > ~/foobar
PATH=~ . foobar
echo $foo $bar
rm ~/foobar
