cat << EOF > /tmp/test_builtin_dot_script.sh
(
EOF
echo before
. /tmp/test_builtin_dot_script.sh
echo after

echo dot_status_code $?
