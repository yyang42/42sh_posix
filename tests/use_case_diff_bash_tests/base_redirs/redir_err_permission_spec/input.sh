FILE=/tmp/redirs_file
touch $FILE
chmod 000 $FILE
ls -l $FILE
echo abc > $FILE
echo status $?
cat -e $FILE
