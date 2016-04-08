set -e
echo msg1 || (exit 42) || echo msg2
echo "should exec"
(exit 42)
echo "should not exec"
