lel ()
{
	myvar=0
	until echo $myvar | cat | grep 99999 ; do
		myvartmp=$myvar
		until [ ${#myvartmp} -eq '1' ]
		do
			myvartmp=${myvartmp##?}
		done
		echo $myvar $myvartmp
		myvar=${myvar%%?}$(( myvartmp + 1 >= 10 ? 90 : myvartmp + 1 ))
	done
}

command -V lel
