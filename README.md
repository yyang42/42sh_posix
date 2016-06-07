# 42sh

A fully POSIX compliant shell

[![Circle CI](https://circleci.com/gh/yyang42/42sh_posix.svg?style=svg&circle-token=6549382dfdf378061c5eb7adf45117da29188496)](https://circleci.com/gh/yyang42/42sh_posix)

## Install
Clone libtowel and moulitest at the same level as your 42sh_posix project
```
git clone git@github.com:juschaef/libtowel.git
git clone git@github.com:yyang42/moulitest.git
$ ls
42sh_posix libtowel moulitest
```

## Compile and Run
```
make
./42sh
```

## Create Objects and Managers
```
make obj obj=product          # create an object
make mgr obj=product          # create a manager
```

## AST-Parser
To run the tests
```
make check_ast
```

**High level view with diff tests**

To have a high level view of the AST, look at the ast\_diff\_tests here:

`/tests/ast_diff_tests/features_ast`

**Low level view with print files**

The recursive print files used to print the AST is a good way to understand how to use the ast

`/srcs/ast/nodes/ast_*/ast_*_print_rec`

**Status**

The AST is not finished. It currently implements (see also diff tests):

- compound_list (commandes separated with ";", "&" or "\n"
- andor "&&" "||"
- pipe "|"
- redirections < > >> << ... (all of them)
- assignment `key=value echo abc`
- simple_command
- compound commands
	- brace_group
	- subshell
	- for_clause
	- case_clause (not yet)
	- if_clause
	- while_clause
	- until_clause

## Command Line
- ctrl + a : move to the begin of the line
- ctrl + b / arrow left : move one char left
- ctrl + c : send SIGINT / clear current line
- ctrl + d : leave shell in case of empty line
- ctrl + e : move to the end of the line 
- ctrl + f / arrow right : move one char right
- ctrl + g : nothing
- ctrl + h : nothing
- ctrl + i : nothing
- ctrl + j / enter : validate current line
- ctrl + k : kill (copy) the text from the cursor to the end of the line
- ctrl + l : clear the screen
- ctrl + m / enter : validate current line
- ctrl + n / arrow down : move down through the history list
- ctrl + o : nothing
- ctrl + p / arrow up : move up through the history list
- ctrl + q : move one word backward
- ctrl + r : nothing
- ctrl + s : move one word forward
- ctrl + t : drag the character before the cursor position
- ctrl + u : kill (copy) the text from the cursor to the begin of the line
- ctrl + v : nothing
- ctrl + w : kill (copy) the word behind the cursor
- ctrl + y : Yank the most recently killed text back
- ctrl + z : send SIGTSTP (ignored)
- delete : remove the character on the left
- suppr / ctrl + d : remove the character on the right
- tabulation : completion of the current word

### Not implemented yet
- ctrl + r : search backward in the history
- ctrl + i : start and end copy mode
- ! : check the last

## Testing Job Control
Test 1:

- ping google.com
- CTRL+Z
- jobs 				# check job is in background and stopped
- bg 				# ping should restart printing its output
- CTRL+Z 			# should NOT stop the task in background

- fg 				# now the job is in foreground
- CTRL+Z 			# should stop the task
- jobs 				# check the task is in background and stopped

- bg 				# should run the task in bg
- kill -TSTP %+     # stop the job
- jobs				# check job in bg and stopped
