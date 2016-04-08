FILE=/tmp/test_builtin_set_noclobber_file
echo aaa >| $FILE
echo status $?
cat $FILE
echo end
