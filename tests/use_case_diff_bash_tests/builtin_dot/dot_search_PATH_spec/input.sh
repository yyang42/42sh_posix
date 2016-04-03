mkdir -p /tmp/test_builtin_dot/
cat << EOF > /tmp/test_builtin_dot/script.sh
echo ABC arg
(exit 42)
EOF

echo "TEST Absolute path"
. /tmp/test_builtin_dot/script.sh

echo "TEST Relative path"
cd /tmp/test_builtin_dot
. ./script.sh

echo "TEST search PATH positive test"
PATH=/tmp/test_builtin_dot
. script.sh
