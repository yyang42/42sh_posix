foo=\''"""\\"{]{]]{}}{'
bar='$$vl""))()#aam'"'''"

echo $foo
echo $bar
echo $foo$baz$bar
echo $bar$foo$baz
echo $baz$bar$foo
echo ${foo}${bar}
echo "$foo"
echo "$bar"
echo "$foo$baz$bar"
echo "$bar$foo$baz"
echo "$baz$bar$foo"
echo "${foo}${bar}"
