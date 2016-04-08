FILE=/tmp/test_builtin_set_noclobber_file
echo abc > $FILE
set -C
echo bbb > $FILE
echo status $?
echo end
