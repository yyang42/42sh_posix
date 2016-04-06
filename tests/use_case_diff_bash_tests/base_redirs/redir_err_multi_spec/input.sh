FILE1=/tmp/test_redir_file1
FILE2=/tmp/test_redir_file2
rm -f $FILE1 $FILE2
touch $FILE1 $FILE2
chmod 000 $FILE1 $FILE2
echo aa > $FILE1 >> $FILE2
