trap "echo abc; exit 42" INT
kill -INT $$
echo "should not exec"
