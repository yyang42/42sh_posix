foo () {
	echo "input " $1
	case $1 in
	    aa*)
	        echo 111
	        ;;
	    *bb)
	        echo 222
	        ;;
	    c*c)
	        echo 333
	        ;;
	    *)
	        echo default case matched
	        ;;
	esac
}

foo aazz
foo aaz
foo az

foo zzbb
foo zzb

foo czzzzzc
foo czzzzz
foo zzzzzc

foo zzzz
