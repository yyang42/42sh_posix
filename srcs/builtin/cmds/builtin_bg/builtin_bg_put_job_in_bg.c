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
        if (kill (job_get_kill_pid(job), SIGCONT) < 0)
        {
            errno_saved = errno;
            shenv_print_error_printf(shenv_singleton(), shenv_get_cur_line(),
                "wait: error: %s", strerror(errno_saved));
            shenv_singleton()->last_exit_code = EXIT_FAILURE;
        }
    }
    else if (job->job_status == JOB_RUNNING)
    {
        shenv_print_error_printf(shenv_singleton(), shenv_get_cur_line(),
            "bg: job %d already in background", job->job_id);
        shenv_singleton()->last_exit_code = EXIT_FAILURE;
    }
    else
    {
        LOG_ERROR("bg: bad job status");
        shenv_singleton()->last_exit_code = EXIT_FAILURE;
    }
}

void                builtin_bg_put_job_in_bg(t_job *job)
{
    put_in_bg(job);
    job->job_status = JOB_RUNNING;
}
