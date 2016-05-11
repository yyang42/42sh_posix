rm -rf /tmp/builtin_set_f_testdir
mkdir -p /tmp/builtin_set_f_testdir
touch /tmp/builtin_set_f_testdir/file{1..10}
echo "======= before set -f"
ls /tmp/builtin_set_f_testdir/*
ls /tmp/builtin_set_f_testdir/*
echo "======= before after -f"
echo "======= before after -f" 1>&2
set -f
ls /tmp/builtin_set_f_testdir/*
echo "======= before after -f 2"
set +f
ls /tmp/builtin_set_f_testdir/*
