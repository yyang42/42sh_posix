export SHLVL=4
env | grep SHLVL=
./42sh -c 'env && ./42sh -c "env"' | grep SHLVL=
