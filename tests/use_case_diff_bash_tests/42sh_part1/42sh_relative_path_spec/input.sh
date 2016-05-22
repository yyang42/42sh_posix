echo "echo abc" > /tmp/42sh_test_file.sh
cd /tmp
echo ">> relative"
$TESTED_SHELL 42sh_test_file.sh
echo ">> absolute"
$TESTED_SHELL /tmp/42sh_test_file.sh
