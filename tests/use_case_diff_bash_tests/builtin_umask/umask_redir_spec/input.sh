FILE=/tmp/builtin_umask_file
rm -f $FILE
umask 777
echo abc > $FILE
echo status $?
cat -e $FILE
chmod 777 $FILE
cat -e $FILE
echo end
