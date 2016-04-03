export var_123="1    2    3"
export -p | grep var_123= | cat -e

export var_dummy=abc jflksdjlfj
export -p | grep var_dummy= | cat -e
