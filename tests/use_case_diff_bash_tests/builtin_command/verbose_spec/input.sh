command -v command ls aa foo

alias aa='ls -laf --'
foo () { echo foo ; }

command -v command ls aa foo
command -v foo bar baz
