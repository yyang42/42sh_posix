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

#include "builtin/cmds/builtin_wait.h"
#include <sys/wait.h>

static void         put_in_wait(t_job *job)
{
    pid_t           pid;
    pid_t           waitpid_ret;
    int             errno_saved;

    pid = - job->pid;
    if (job->job_status == JOB_RUNNING)
    {
        LOGGER_INFO("wait for job %d to complete", pid);
        waitpid_ret = waitpid(job->pid, &job->status, 0);
        if (waitpid_ret < 0)
        {
            errno_saved = errno;
            shenv_print_error_printf(shenv_singleton(), shenv_get_cur_line(),
                "wait: error: %s", strerror(errno_saved));
            shenv_singleton()->last_exit_code = EXIT_FAILURE;
        }
        else if (waitpid_ret > 0)
        {
            if (WIFEXITED(job->status))
                job->job_status = JOB_DONE;
        }
    }
    else if (job->job_status == JOB_STOPPED)
    {
        shenv_print_error_printf(shenv_singleton(), shenv_get_cur_line(),
            "wait: warning: job %d is stopped", job->job_id);
        shenv_singleton()->last_exit_code = WAIT_ERROR_ALREADY_STOPPED;
    }
    else
    {
        LOGGER_INFO("wait: pid=%d: trying to continue a non stopped job", job->pid);
    }
}

void                builtin_wait_put_job_in_wait(t_job *job)
{
    put_in_wait(job);
}
