echo ` echo ` echo abc ` echo abc `

`echo e``echo c``echo h``echo o` `$(echo e)$(echo c)$(echo h)$(echo o) echo`

echo `echo \'\'\"\"\\\\\'\'`

myfn () { echo 'echo ' ; }
echo `\`myfn\`abc`
