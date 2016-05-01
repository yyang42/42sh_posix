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

#include "builtin/cmds/builtin_bg.h"
#include <sys/wait.h>

static void         put_in_bg(t_job *job)
{
    int             errno_saved;

    if (job->job_status == JOB_STOPPED)
    {
        LOG_INFO("bg: continue pid=%d", job_get_kill_pid(job));
        if (kill(job_get_kill_pid(job), SIGCONT) < 0)
        {
            errno_saved = errno;
            shenv_singl_error(EXIT_FAILURE,
                "wait: error: %s", strerror(errno_saved));
        }
    }
    else if (job->job_status == JOB_RUNNING)
    {
        shenv_singl_error(EXIT_FAILURE,
            "bg: job %d already in background", job->job_id);
    }
    else
    {
        shenv_singl_error(EXIT_FAILURE, "bg: bad job status");
    }
}

void                builtin_bg_put_job_in_bg(t_job *job)
{
    job_print(job, 0);
    put_in_bg(job);
    job->job_status = JOB_RUNNING;
}
