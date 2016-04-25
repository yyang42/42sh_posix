send_key () {
    tmux send-keys -t TEST42SH "$1"
}

send_line () {
  send_key "$1"$'\n'
}

send_line "$TEST_SHELL"
