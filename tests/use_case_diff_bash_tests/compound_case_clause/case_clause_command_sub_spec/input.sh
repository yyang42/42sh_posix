complex () {
    case $1 in
    [1-6]*)
        echo case 1-6
        ;;
    [7-8]*)
        echo case 7-8
        ;;
    9[1-8])
        echo case 9x
        ;;
    99)
        echo case 99
        ;;
    *)
        echo case star
        ;;
    esac
}

complex a
complex 1
complex 2
complex 6
complex 7
complex 8
complex 9
complex 10
complex 50
complex 90
complex 91
complex 95
complex 98
complex 99
complex 100
