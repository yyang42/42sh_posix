lel ()
{
	for i in aa bb cc dd ee ff gg hh ii
	do
		echo $i
		echo $i &
		echo $i
	done &
	for i in $( ls -la | awk -F' ' '{ $0=$3 }$0') $( find srcs . -name '*ast*')
	do
		( ls | (ls -la) | cat -e) &
		echo $(sleep 2) && echo `pwd` &
	done
}

command -V lel
