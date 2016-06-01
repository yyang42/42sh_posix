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

#include "job_control/job.h"
#include "job_control/jobexec.h"
#include "utils.h"

static void         job_exec_fn(t_job *job, void *ctx)
{
    int             kill_ret;

    LOG_INFO("job_put_in_fg: job_exec_fn: pid: %d", job->pid);
    kill_ret = kill(job_get_kill_pid(job), SIGCONT);
    if (kill_ret == 0)
    {
        if (tcsetpgrp(STDIN_FILENO, job->pid) < 0)
            LOG_ERROR("tcsetpgrp: %s", strerror(errno));
    }
    else if (kill_ret < 0)
    {
        LOG_ERROR("kill: %s, %d", strerror(errno), job_get_kill_pid(job));
        shenv_singleton()->last_exit_code = EXIT_FAILURE;
    }
    job_utils_waitpid(job->pid, &job->status);
    job_print_if_stopped(job);
    if(tcsetpgrp(STDIN_FILENO, getpid()) < 0)
        LOG_ERROR("tcsetpgrp: %s", strerror(errno));
    (void)ctx;
}

void	         	job_put_in_fg(t_job *job)
{
    jobexec_fork_exec_interactive_job_sig_wrapper(job, NULL, job_exec_fn);
    // job_del(job);
}
