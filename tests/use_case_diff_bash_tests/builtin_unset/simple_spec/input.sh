localvar=123
export globalvar=456
echo $localvar
echo $globalvar
env | grep localvar=
env | grep globalvar=
unset localvar
unset globalvar
echo $localvar
echo $globalvar
env | grep localvar=
env | grep globalvar=
