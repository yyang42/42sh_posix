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

#include "builtin/builtin.h"
#include "data.h"
#include "builtin/cmds/builtin_kill.h"

void				builtin_kill_update_job(t_job *job, int signum)
{
	if (signum == SIGCONT)
	{
		job->job_status = JOB_RUNNING;
	}
	else if (signum == SIGKILL)
	{
		job->job_status = JOB_TERMINATED;
	}
}
