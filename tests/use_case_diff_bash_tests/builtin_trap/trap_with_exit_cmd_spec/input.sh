trap "echo abc; exit 42" INT
kill -INT `bash -c 'echo $PPID'`
echo "should not exec"
