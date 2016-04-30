lel ()
{
	a=12 command1 > cmd1 < cmd2 >> cmd3
	b=`echo a`$((1+1))$(echo b) command2 2>&1 <&42 >&22
	command3 << EOF; }
123
345
567
EOF
command -V lel

lol()
{
	b=4444 > pouet
	{
		command1;
		command2&
		command3
		command4;
	} > lel < lol 3>> pouf
	a=123 < pouf
}

command -V lol
