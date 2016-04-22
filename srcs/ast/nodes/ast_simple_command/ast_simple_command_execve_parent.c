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
#include "shsignal/shsignal_mgr.h"
#include "data.h"

static jmp_buf jump_buf;

static void     intercept_logger_handler(int sig)
{
  LOGGER_DEBUG("INTERACTIVE: Ignore signal %s(%d)", shsignal_mgr_get_signame(data_signals(), sig), sig);
  LOGGER_DEBUG("INTERACTIVE: pid (%d)", getpid());
  (void)sig;
}

static void         sigtstp_handler(int sig)
{
    LOGGER_INFO("SIGTSTP handler: %d", sig);
    longjmp(jump_buf, 1);
}

static void         sig_int_quit_handler(int sig)
{
    LOGGER_INFO("SIGINT handler: pid: %d", sig, shenv_singleton()->jc_foreground_job_pid);
    if (shenv_singleton()->jc_foreground_job_pid)
    {
        if (kill(-shenv_singleton()->jc_foreground_job_pid, sig) == -1)
        {
            LOGGER_ERROR("kill: %s", strerror(errno));
        }
    }
}

static void         ast_simple_command_execve_parent_wait_catch_sigs(t_ast_simple_command *cmd, pid_t pid)
{
    sig_t           saved_sig_handler;
    sig_t           saved_sigint_handler;
    sig_t           saved_sigquit_handler;
    t_job           *job;

    saved_sig_handler = signal(SIGTSTP, sigtstp_handler);
    saved_sigint_handler = signal(SIGINT, sig_int_quit_handler);
    saved_sigquit_handler = signal(SIGQUIT, sig_int_quit_handler);
    shenv_singleton()->jc_foreground_job_pid = pid;
    LOGGER_INFO("set SIGTSTP handler");
    if (setjmp(jump_buf) == 0)
    {
        ast_simple_command_execve_parent_wait(pid);
    }
    else
    {
        job = ast_list_item_exec_async_parent_create_job(cmd->all_tokens, pid);
        if (kill(-pid, SIGTSTP) == -1)
            LOGGER_ERROR("kill: %s", strerror(errno));
    }
    shenv_singleton()->jc_foreground_job_pid = 0;
    signal(SIGTSTP, saved_sig_handler);
    signal(SIGINT, saved_sigint_handler);
    signal(SIGQUIT, saved_sigquit_handler);
    (void)intercept_logger_handler;
}

void				ast_simple_command_execve_parent(t_ast_simple_command *cmd, pid_t pid)
{
    if (shenv_singleton()->shenv_is_inside_job_control)
    {
        ast_simple_command_execve_parent_wait(pid);
    }
    else
    {
        ast_simple_command_execve_parent_wait_catch_sigs(cmd, pid);
    }
}
