echo start
myvar_aaa=111
readonly myvar_aaa
unset myvar_aaa
echo status $?
echo end
