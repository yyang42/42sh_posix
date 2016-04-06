FILE=/tmp/builtin_umask_file
rm -f $FILE
umask 777
touch $FILE
echo abc > $FILE
ls -l $FILE
chmod 777 $FILE
echo aa >> $FILE
cat -e $FILE
