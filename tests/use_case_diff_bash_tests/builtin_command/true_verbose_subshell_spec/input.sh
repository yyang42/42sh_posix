lel () {
	( a=b && c=d || ls -la & command2 && (command 3); echo abc | cat -e)
	( ( ( ( command lel ) ) & ) ) 2> pouf
}

command -V lel
