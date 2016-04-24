export myvar=456
env myvar=123 exec bash '-c' 'echo abc123 $myvar'
