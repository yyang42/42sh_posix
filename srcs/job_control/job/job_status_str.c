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

#include <sys/wait.h>
#include <errno.h>
#include "job_control/job.h"
#include "shsignal/shsignal_mgr.h"
#include "data.h"

char				*job_status_str(t_job *job)
{
	char			*str_status;

	str_status = NULL;
	if (job->job_status == JOB_RUNNING)
		str_status = twl_strdup("Running");
	else if (job->job_status == JOB_DONE)
	{
		if (WEXITSTATUS(job->status) == 0)
			str_status = twl_strdup("Done");
		else
			twl_asprintf(&str_status, "Done(%d)", WEXITSTATUS(job->status));
	}
	else if (job->job_status == JOB_TERMINATED)
	{
		twl_asprintf(&str_status, "Terminated: %d", WTERMSIG(job->status));
	}
	else if (job->job_status == JOB_STOPPED)
	{
		twl_asprintf(&str_status, "Stopped(SIG%s)",
			shsignal_mgr_get_signame(data_signals(), job->stopped_signal));
	}
	else
	{
		str_status = twl_strdup("Unknown");
	}
	return (str_status);
}
