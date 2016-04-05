readonly readonly_myvar1=abc
readonly readonly_myvar2=

readonly -p | grep readonly_myvar
env | grep readonly_myvar
export | grep readonly_myvar
