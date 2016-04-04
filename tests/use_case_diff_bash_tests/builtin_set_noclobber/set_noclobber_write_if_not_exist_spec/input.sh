FILE=/tmp/test_builtin_set_noclobber_file
rm -f $FILE
set -C
echo aaa > $FILE
echo bbb > $FILE
echo status $?
cat $FILE
echo end
