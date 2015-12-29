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
- subshell

Not implemented:

- All the expansion stuff
- The rest

The AST-Parser is compliant with the Tokenization Rules and the POSIX Shell Grammar.
It something is wrong, please raise an issue.
