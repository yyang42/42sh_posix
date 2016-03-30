eval "echo abc"
eval "echo   abc"

myvar=42
eval "echo  $myvar  abc"
eval 'echo  $myvar  abc'

myvar=43 eval echo aaa$myvar
