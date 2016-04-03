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

#include "ast/nodes/ast_list_item.h"
#include "ast/nodes/ast_simple_command.h"
#include "logger.h"
#include "shsignal/shsignal.h"
#include <setjmp.h>
#include <sys/wait.h>

static jmp_buf jump_buf;

static void         sigtstp_handler(int sig)
{
    LOGGER_INFO("SIGTSTP handler: %d", sig);
    longjmp(jump_buf, 1);
}

static void         ast_simple_command_execve_parent_wait_catch_stop(t_ast_simple_command *cmd, pid_t pid)
{
    sig_t           saved_sig_handler;

    saved_sig_handler = signal(SIGTSTP, sigtstp_handler);
    setpgid(pid, pid);
    LOGGER_DEBUG("ast_simple_command_execve_parent_wait_catch_stop: %d", shenv_singleton()->shenv_is_inside_job_control);
    if (setjmp(jump_buf) == 0)
    {
        ast_simple_command_execve_parent_wait(pid);
    }
    else
    {
        if (kill(-pid, SIGTSTP) == -1)
            shenv_singl_error(EXIT_FAILURE, "kill: %s", strerror(errno));
        ast_list_item_exec_async_parent_create_job(cmd->full_command_tokens, pid);
    }
   signal(SIGTSTP, saved_sig_handler);
}

void				ast_simple_command_execve_parent(t_ast_simple_command *cmd, pid_t pid)
{
    if (shenv_singleton()->shenv_is_inside_job_control)
    {
        LOGGER_DEBUG("job1: %d", shenv_singleton()->shenv_is_inside_job_control);
        ast_simple_command_execve_parent_wait(pid);
    }
    else
    {
        LOGGER_DEBUG("job2: %d", shenv_singleton()->shenv_is_inside_job_control);
        ast_simple_command_execve_parent_wait_catch_stop(cmd, pid);
    }
}
