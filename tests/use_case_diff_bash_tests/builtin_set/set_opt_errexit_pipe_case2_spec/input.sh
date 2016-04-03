set -e
echo msg1 || (exit 42)
echo "should not exec"
