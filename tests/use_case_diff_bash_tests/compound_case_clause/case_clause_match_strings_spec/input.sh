foo () {
	echo "input " $1
	case $1 in
	    aa)
	        echo aa case matched
	        ;;
	    bb)
	        echo bb case matched
	        ;;
	    *)
	        echo default case matched
	        ;;
	esac
}

foo bb
foo aa
# foo zz
