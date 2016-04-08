export test_var1=111
export test_var2=222
export test_var3=333
echo $test_var1 $test_var2 $test_var3
env | grep test_var | sort
unsetenv test_var1 test_var2 test_var3
env | grep test_var | sort
