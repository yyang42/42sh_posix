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

#include "builtin/cmds/builtin_fg.h"
#include "shsignal/shsignal_mgr.h"
#include "data.h"
#include <setjmp.h>
#include <sys/wait.h>

void                builtin_fg_put_job_in_fg(t_job *job, t_token *cmd_token)
{
    if (job_has_terminated(job))
    {
        shenv_print_error_printf(shenv_singleton(), cmd_token->line,
            "fg: job has terminated");
        return ;
    }
    if (job_mgr_pop(shenv_singleton()->jobs, job) == NULL)
    {
        shenv_singl_error(1, "fg: fail to pop job from jobs (pid=%d)", job->pid);
        return ;
    }
    twl_printf("%s\n", job->cmd_str);
    job_put_in_fg(job);
}
