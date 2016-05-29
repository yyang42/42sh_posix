mkdir -p /tmp/42sh_dot_dot_test_folder
cd /tmp/42sh_dot_dot_test_folder
mkdir -p mydir
cd mydir
cp /bin/echo .
../../42sh_dot_dot_test_folder/mydir/echo abc
