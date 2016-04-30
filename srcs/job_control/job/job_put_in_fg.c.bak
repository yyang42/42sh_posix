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

#include <setjmp.h>

#include "job_control/job.h"
#include "job_control/job_mgr.h"
#include "shsignal/shsignal_mgr.h"
#include "data.h"

static jmp_buf jump_buf;

static void     intercept_logger_handler(int sig)
{
  LOG_DEBUG("INTERACTIVE: Ignore signal %s(%d)", shsignal_mgr_get_signame(data_signals(), sig), sig);
  LOG_DEBUG("INTERACTIVE: pid (%d)", getpid());
  (void)sig;
}

static void         sigtstp_handler(int sig)
{
    LOG_INFO("SIGTSTP handler: %d", sig);
    longjmp(jump_buf, 1);
    (void)sig;
}

static void         sig_int_quit_handler(int sig)
{
    LOG_INFO("SIGINT/QUIT handler: pid: %d", sig, shenv_singleton()->jc_foreground_job_pid);
    if (shenv_singleton()->jc_foreground_job_pid)
    {
        if (kill(-shenv_singleton()->jc_foreground_job_pid, sig) == -1)
        {
            LOG_ERROR("kill: %s", strerror(errno));
        }
    }
}

static void			handle_sigcont(t_job *job)
{
    if (job->job_status == JOB_STOPPED)
    {

        if (kill(job_get_kill_pid(job), SIGCONT) < 0)
        {
            LOG_ERROR("kill (SIGCONT): pid: %d", job_get_kill_pid(job));
            shenv_singleton()->last_exit_code = EXIT_FAILURE;
        }
    }
}

// static void         tcsetpgrp_wrapper(int fd, pid_t pid)
// {
//     // if (!isatty(fd))
//     //     return ;
//     if (tcsetpgrp(fd, pid) == -1)
//         LOG_ERROR("tcsetpgrp: fd=%d pid=%d: %s",fd, pid, strerror(errno));
// }

void	         	job_put_in_fg(t_job *job)
{
    twl_printf("%s\n", job->cmd_str);
    // tcsetpgrp_wrapper(STDIN_FILENO, job->pid);
    job_utils_waitpid(job->pid);
    // tcsetpgrp_wrapper(STDIN_FILENO, getpid());
    (void)handle_sigcont;
    (void)sig_int_quit_handler;
    (void)sigtstp_handler;
    (void)intercept_logger_handler;
    // sig_t           saved_sig_handler;
    // sig_t           saved_sigint_handler;
    // sig_t           saved_sigquit_handler;

    // saved_sig_handler = signal(SIGTSTP, sigtstp_handler);
    // saved_sigint_handler = signal(SIGINT, sig_int_quit_handler);
    // saved_sigquit_handler = signal(SIGQUIT, sig_int_quit_handler);
    // shenv_singleton()->jc_foreground_job_pid = job->pid;
    // LOG_INFO("set SIGTSTP handler");
    // if (setjmp(jump_buf) == 0)
    // {
    // 	handle_sigcont(job);
    //     job_utils_waitpid(job->pid);
    //     job_del(job);
    // }
    // else
    // {
    //     LOG_INFO("kill(%d, SIGTSTP)", job_get_kill_pid(job));
    //     if (kill(job_get_kill_pid(job), SIGTSTP) == -1)
    //         LOG_ERROR("kill: %s", strerror(errno));
    //     job_mgr_env_push(job);
    // }
    // shenv_singleton()->jc_foreground_job_pid = 0;
    // signal(SIGTSTP, saved_sig_handler);
    // signal(SIGINT, saved_sigint_handler);
    // signal(SIGQUIT, saved_sigquit_handler);
    // (void)intercept_logger_handler;
}
