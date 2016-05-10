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
#include "shenv/shenv.h"

bool				job_exec_update_status(t_job *job)
{
	char	*str_status;

	if (WIFSTOPPED(job->status))
	{
		job->stopped_signal = WSTOPSIG(job->status);
		job->job_status = JOB_STOPPED;
	}
	else if (WIFCONTINUED(job->status))
		job->job_status = JOB_RUNNING;
	else if (WIFEXITED(job->status))
		job->job_status = JOB_DONE;
	else if (WIFSIGNALED(job->status))
		job->job_status = JOB_TERMINATED;
	else
		job->job_status = -1;
	str_status = job_status_str_long(job, true);
	LOG_INFO("job %d status: %s ", job->job_id, str_status);
	free(str_status);
	if (!shenv_singleton()->shenv_is_interactive)
		return (false);
	if (shenv_flag_exist(shenv_singleton(), "b"))
	{
		job_print(job, 0);
		return (job_has_terminated(job));
	}
	return (false);
}
