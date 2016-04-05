readonly readonly_myvar1=abc
readonly_myvar2=111
echo readonly_myvar2: $readonly_myvar2
readonly_myvar2=222
readonly readonly_myvar2
readonly readonly_myvar3

readonly -p | grep readonly_myvar
export -p | grep readonly_myvar
env | grep readonly_myvar

echo "============================"
export readonly_myvar1
readonly -p | grep readonly_myvar
export -p | grep readonly_myvar
env | grep readonly_myvar
