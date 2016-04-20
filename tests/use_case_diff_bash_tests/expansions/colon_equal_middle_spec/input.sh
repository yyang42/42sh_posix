echo ${x:=  aa  bb  cc  }
echo "$x"
unset x
echo ${x:=~ `echo lol` "$((1+12))" pouf}
echo "$x"
unset x
echo ${x:=/*/}
echo $x
unset x

echo "${x:=  aa  bb  cc  }"
echo "$x"
unset x
echo "${x:=~ `echo lol` "$((1+12))" pouf}"
echo "$x"
unset x
echo "${x:=/*/}"
echo $x
unset x
