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

#include "job_control/jobexec.h"
#include "utils.h"
#include <setjmp.h>

t_lst               *data_tmp_jobs(void)
{
    static t_lst    *jobs = NULL;

    if (jobs == NULL)
        jobs = twl_lst_new();
    return (jobs);
}


static void         push_job(t_job *job)
{
    if(tcsetpgrp(0, getpid()) < 0)
        LOG_ERROR("tcsetpgrp: %s", strerror(errno));
    if(kill(job_get_kill_pid(job), SIGTSTP) < 0)
        LOG_ERROR("kill: %s", strerror(errno));
    job_mgr_env_push(job);
}


static void			sigstp_catcher(int signum, siginfo_t *info, void *vp)
{
    t_job           *job;
    pid_t           gid;

    gid = getpgid(info->si_pid);
    LOG_INFO("signum: %d, Signal %d from PID %d, code: %d, value: %d: gid: %d",
    	signum, info->si_signo, (int)info->si_pid, info->si_code, info->si_value, gid);
    if (info->si_code == CLD_STOPPED)
	{
        LOG_INFO("child stopped: %d", info->si_pid);
        LOG_INFO("data_tmp_jobs() len: %d", twl_lst_len(data_tmp_jobs()));
        job = job_mgr_find_by_pid(data_tmp_jobs(), info->si_pid);
        if (!job)
        {
            LOG_INFO("search in shenv->jobs");
            job = job_mgr_find_by_pid(shenv_singleton()->jobs, info->si_pid);
        }
        if (job)
        {
            LOG_DEBUG("info->si_pid: %d", info->si_pid);
            LOG_DEBUG("job->pid: %d", job->pid);
            push_job(job);
        }
        else
        {
            LOG_INFO("pid not found: %d", info->si_pid);
        }
	}
    (void)vp;
}

static void			sig_handler_init(int signum, struct sigaction *sa, struct sigaction *oldsa)
{
    sa->sa_flags = SA_SIGINFO | SA_RESTART;
    sa->sa_sigaction = sigstp_catcher;
    sigemptyset(&sa->sa_mask);
    if (sigaction(signum, sa, oldsa) != 0)
    {
        int errnum = errno;
        LOG_ERROR("Failed to set signal handler (%d: %s)\n", errnum, strerror(errnum));
        exit(1);
    }
}

void				jobexec_fork_exec_interactive_job_sig_wrapper(t_job *job, void *ctx,
					void (exec_interactive_fn)(t_job *job, void *ctx))
{
	struct sigaction sa;
	struct sigaction oldsa;

    LOG_INFO("jobexec_fork_exec_interactive_job_sig_wrapper");
    LOG_INFO("tmp jobs len: %d: job->pid: %d (before exec)",
        twl_lst_len(data_tmp_jobs()), job->pid);
    sig_handler_init(SIGCHLD, &sa, &oldsa);
    twl_lst_push_back(data_tmp_jobs(), job);
    exec_interactive_fn(job, ctx);
    job_mgr_pop(data_tmp_jobs(), job);
    LOG_INFO("tmp jobs len: %d: job->pid: %d (after exec)",
        twl_lst_len(data_tmp_jobs()), job->pid);
    if (!job_mgr_find_by_pid(shenv_singleton()->jobs, job->pid))
        job_del(job);
}
