test_var1='echo abc'
test_var2='abc'
test_var4="a'b"
set | grep test_var | grep -v _= > /tmp/builtin_set_stdout

echo "/tmp/builtin_set_stdout content:"
cat /tmp/builtin_set_stdout
unset test_var1

echo
echo "test_var1 is unset so grep should fail"
set | grep test_var | grep -v _=
set | grep test_var1=
echo "grep exit status $?"

echo
echo "sourcing the stdout should set test_var1"
. /tmp/builtin_set_stdout
set | grep test_var1=
