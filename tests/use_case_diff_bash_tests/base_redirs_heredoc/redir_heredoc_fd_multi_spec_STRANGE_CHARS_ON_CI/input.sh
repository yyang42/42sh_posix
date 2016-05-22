# https://circleci.com/gh/yyang42/42sh_posix/1353
# Strange chars on CI
(
	read var1 var2 <&5
	echo "$var1-$var2"
	read var1 var2 <&5
	echo "$var1-$var2"
	read var1 var2 <&5
	echo "$var1-$var2"
	read var1 var2 <&6
	echo "$var1-$var2"
	read var1 var2 <&6
	echo "$var1-$var2"
	read var1 var2 <&6
	echo "$var1-$var2"
)  5<< EOF 6<< EOF2
A1 A2
B1 B2
EOF
11 12
21 22
EOF2
