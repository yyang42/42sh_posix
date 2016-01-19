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
- Arrow left / right :  Move 1 char left or right
- ctrl + a : begin of the line
- ctrl + e : end of line
- delete : remove previous char
- ctrl + t : on word after
- ctrl + u : on word before
- ctrl + w : remove prev word
- arrow up / down : navigate on history
- history cmd : print history
- multiline

### Not implemented yet
- copy / paste
- search in history
-
