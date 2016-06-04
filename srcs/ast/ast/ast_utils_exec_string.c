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


static void         block_sigchld(void)
{
    sigset_t        blockMask;

    LOG_DEBUG("block SIGCHLD");
    sigemptyset(&blockMask);
    sigaddset(&blockMask, SIGCHLD);
    if (sigprocmask(SIG_BLOCK, &blockMask, NULL) == -1)
        LOG_ERROR("sigprocmask");

}

static void         unblock_sigchld(void)
{
    sigset_t        blockMask;

    LOG_DEBUG("unblock SIGCHLD");
    sigemptyset(&blockMask);
    sigaddset(&blockMask, SIGCHLD);
    if (sigprocmask(SIG_UNBLOCK, &blockMask, NULL) == -1)
        LOG_ERROR("sigprocmask");

}

static void         ast_utils_exec_string_with_sig_handling(char *input, int line)
{
    sigset_t        blockMask;

    sigemptyset(&blockMask);
    sigaddset(&blockMask, SIGCHLD);
    block_sigchld();
    jobexec_fork_utils_init_sigchld_handler();
    ast_utils_exec_string_inner(input, line);;
    unblock_sigchld(); /* TODO: Find a better way */
    block_sigchld(); /* TODO: Find a better way */
}

void                ast_utils_exec_string(char *input, int line)
{
    LOG_DEBUG("ast_utils_exec_string");
    if (shenv_singleton()->shenv_is_function_or_script)
        ast_utils_exec_string_inner(input, line);
    else
        ast_utils_exec_string_with_sig_handling(input, line);
    job_mgr_wait_update(shenv_singleton()->jobs);
}
