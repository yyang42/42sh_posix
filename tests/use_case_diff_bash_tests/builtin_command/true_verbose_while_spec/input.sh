lel ()
{
	i=100
	while echo abc & (echo lel; echo pouet) && [ $(( (i -= 1) )) -ne 0 ]
	do
		j=0
		while ( for i in aa bb cc; do echo $i; done ); echo $((j+=1)) && [ $j -lt 100 ]
		do
			echo $((i * j))
		done
	done
}

command -V lel
