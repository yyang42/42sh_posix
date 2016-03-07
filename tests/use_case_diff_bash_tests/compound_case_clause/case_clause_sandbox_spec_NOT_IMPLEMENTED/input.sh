export myvar=zz*
case zzx in
    aa)
        echo aa case matched
        ;;
    $myvar)
        echo bb case matched
        ;;
    *)
        echo default case matched
        ;;
esac
