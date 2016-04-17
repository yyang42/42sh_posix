echo ~root/../../bin/ls
echo "~root/../../bin/ls"

echo ~doesntexist/hihi
echo "~doesntexist/hihi"

echo ~$((1/1))"c'est chaud"
echo '~$((1/1))"c'\''est chaud"'

a='~'

echo $a
