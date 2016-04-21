mkdir -p /tmp/test_binary_path
echo "echo abc" > /tmp/test_binary_path/myexec
chmod 755 /tmp/test_binary_path/myexec
echo "=======1"
myexec
echo "=======2"
export PATH="/tmp/test_binary_path:$PATH"
myexec
echo "=======3"
/tmp/test_binary_path/myexec
echo "=======4"
export PATH=
myexec &> /dev/null
echo $?
echo "=======5"
