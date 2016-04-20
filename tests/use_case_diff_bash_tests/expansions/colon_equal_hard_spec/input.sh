x=${x:=woops   j'ai   fait   des bêtises  :') }
echo $x
unset x
echo ${x:=aaa`python -c 'print "aa bb-"*44 + "aa bb"'`bbb}
python -c 'import sys;print sys.argv' $x
unset x

x="${x:=woops   j'ai   fait   des bêtises  :') }"
echo $x
unset x
echo "${x:=aaa`python -c 'print "aa bb-"*44 + "aa bb"'`bbb}"
python -c 'import sys;print sys.argv' $x
unset x
