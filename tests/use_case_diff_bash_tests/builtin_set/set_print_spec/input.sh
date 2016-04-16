test_set_newline='newline

bb'
set | grep -A 2 test_set_newline

test_set_var0='simplestring'
test_set_var1='tabs		bb'
test_set_var2='dollar$'
test_set_var3='space bb'
test_set_var4="space bb"
test_set_var5="space_?^bb"
test_set_var6="space_bb"
test_set_var7="space1bb"
test_set_var7="space@bb"
set | grep -A 2 test_set_var
