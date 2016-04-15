tes_set_newline='newline

bb'
set | grep -A 2 tes_set_newline

tes_set_var0='simplestring'
tes_set_var1='tabs		bb'
tes_set_var2='dollar$'
tes_set_var3='space bb'
tes_set_var4="space bb"
tes_set_var5="space_?^bb"
tes_set_var6="space_bb"
tes_set_var7="space1bb"
tes_set_var7="space@bb"
set | grep -A 2 tes_set_var
