export pipe_myvar1=aa
export pipe_myvar2=bbbb
env | grep pipe_myvar | wc | cat -e
