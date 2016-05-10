cat << EOF | $TESTED_SHELL -o noclobber -o allexport -f
set -o | sort | grep -E '^(allexport|errexit|noclobber|noglob|notify|ignoreeof|monitor|noexec|nounset|verbose|vi)'
EOF
