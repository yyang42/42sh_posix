complex () {
    case $1 in
    `echo a`*)
        Message="I am 1"
        ;;
    [1-6]*)
        Message="All is quiet."
        ;;
    esac
}

complex a ; echo $Message
complex 1 ; echo $Message
