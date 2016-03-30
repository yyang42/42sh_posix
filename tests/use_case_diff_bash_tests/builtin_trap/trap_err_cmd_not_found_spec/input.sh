trap "this_cmd_do_not_exist" 30; trap; kHUP -30 `bash -c 'echo $PPID'`
