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
    /* Send the job a continue signal, if necessary.  */
    if (true)
    {
        COUCOU
        if (kill (job->pid, SIGCONT) < 0)
        {
        COUCOU
            twl_dprintf(2, "kill (SIGCONT)");
        }
        COUCOU
    }
}

void                builtin_bg_put_job_in_bg(t_job *job)
{
    job->job_status = JOB_RUNNING;
    put_in_bg(job);
}
