echo ======0
foo () {
    echo =====a1
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
    echo =====a2
}
echo ======1
foo bb
# foo aa
# foo zz
