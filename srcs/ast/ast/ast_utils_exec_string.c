/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 41:59:59 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast/ast.h"
#include "token/token_mgr.h"
#include "job_control/jobexec.h"

static void         sigprocmask_wrapper(int how, const sigset_t *restrict set)
{
    if (sigprocmask(how, set, NULL) == -1)
    {
        LOG_ERROR("sigprocmask");
    }
}

static void         ast_utils_exec_string_with_sig_handling(char *input, int line)
{
    sigset_t        blockMask;

    sigemptyset(&blockMask);
    sigaddset(&blockMask, SIGCHLD);
    sigprocmask_wrapper(SIG_BLOCK, &blockMask);
    jobexec_fork_utils_init_sigchld_handler();
    ast_utils_exec_string_inner(input, line);;
    sigprocmask_wrapper(SIG_UNBLOCK, &blockMask);
}

void                ast_utils_exec_string(char *input, int line)
{
    if (shenv_singleton()->shenv_is_function_or_script)
        ast_utils_exec_string_inner(input, line);
    else
        ast_utils_exec_string_with_sig_handling(input, line);
}
