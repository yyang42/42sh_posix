
unset X
echo ${X:=abc}
X=pouet
echo ${X:=abc}
