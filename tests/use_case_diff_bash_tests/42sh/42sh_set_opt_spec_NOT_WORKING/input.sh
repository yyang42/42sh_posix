cat << EOF | $TESTED_SHELL -aC
set -o | sort | grep -E '^(allexport|errexit|noclobber|noglob|notify|ignoreeof|monitor|noexec|nounset|verbose|vi)'
EOF
