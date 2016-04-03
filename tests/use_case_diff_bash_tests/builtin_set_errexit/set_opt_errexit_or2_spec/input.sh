set -e
(exit 42) || echo msg1
echo status $?
echo "should exec"
