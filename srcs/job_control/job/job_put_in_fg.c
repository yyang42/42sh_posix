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

static void         job_exec_fn(void *job_)
{
    t_job           *job;
    int             kill_ret;

    job = job_;
    LOG_DEBUG("job_exec_fn called: pid: %d", job->pid);
    kill_ret = kill(job_get_kill_pid(job), SIGCONT);
    if (kill_ret == 0)
    {
        EXEC_LOG_ERRNO(tcsetpgrp(STDIN_FILENO, job->pid));
    }
    else if (kill_ret < 0)
    {
        LOG_ERROR("kill: %d", job_get_kill_pid(job));
        shenv_singleton()->last_exit_code = EXIT_FAILURE;
    }
    job_utils_waitpid(job->pid);
    EXEC_LOG_ERRNO(tcsetpgrp(STDIN_FILENO, getpid()));
}

void	         	job_put_in_fg(t_job *job)
{
    twl_printf("%s\n", job->cmd_str);
    jobexec_fork_exec_interactive_job_sig_wrapper(job, job, job_exec_fn);
}
