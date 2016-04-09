trap '' HUP
trap 'echo parent' INT

echo "Subshell should NOT be able to set ignored trap"
(
	trap 'echo subshell' HUP INT
	echo "trap list from subshell"
	trap
)
echo
echo "trap list from parent"
trap
echo
echo "Brace group should be able to set ignored trap"
{
	trap 'echo brace group' HUP INT
	echo "trap list from brace group"
	trap
}
echo
echo "trap list from parent"
trap
