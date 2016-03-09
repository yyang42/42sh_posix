foo () {
	echo "input " $1
	case $1 in
	    aa)
	        echo aa case matched
	        ;;
	    bb |cc| dd | ee)
	        echo bb/cc/dd/ee case matched
	        ;;
	    *)
	        echo default case matched
	        ;;
	esac
}

foo aa
foo bb
foo cc
foo dd
foo ee
foo zz
