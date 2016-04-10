trap "this_cmd_do_not_exist" HUP; trap; kill -HUP $$
