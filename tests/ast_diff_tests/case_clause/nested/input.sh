space=a
case $space in
42*)
    echo 42A
	case $space in
	21*)
	    echo 21A
	    ;;
	*)
	    echo 21B
	esac
    ;;
*)
    echo 42B
esac
echo $Message
