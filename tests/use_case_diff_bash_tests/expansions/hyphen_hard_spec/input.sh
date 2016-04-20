python -c 'import sys; print sys.argv' ${x- a b c d e}
python -c 'import sys; print sys.argv' ${x-" a b c d e "}
python -c 'import sys; print sys.argv' ${x-1$(echo "a b c")d}
python -c 'import sys; print sys.argv' ${x-""\\""}
python -c 'import sys; print sys.argv' ${x-~"foo"$(echo bar)"`echo baz`"}
python -c 'import sys; print sys.argv' ${x-~ "foo" $(echo bar) "` echo baz ` "}

python -c 'import sys; print sys.argv' "${x- a b c d e}"
python -c 'import sys; print sys.argv' "${x-" a b c d e "}"
python -c 'import sys; print sys.argv' "${x-1$(echo "a b c")d}"
python -c 'import sys; print sys.argv' "${x-""\\""}"
python -c 'import sys; print sys.argv' "${x-~"foo"$(echo bar)"`echo baz`"}"
python -c 'import sys; print sys.argv' "${x-~ "foo" $(echo bar) "` echo baz ` "}"
