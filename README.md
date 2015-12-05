# 42sh

A fully POSIX compliant shell

[![Circle CI](https://circleci.com/gh/yyang42/42sh_posix.svg?style=svg&circle-token=6549382dfdf378061c5eb7adf45117da29188496)](https://circleci.com/gh/yyang42/42sh_posix)

## Install
Clone the libtowel at the same level as your 42sh_posix project
```
git clone git@github.com:juschaef/libtowel.git
$ ls
42sh_posix libtowel
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
