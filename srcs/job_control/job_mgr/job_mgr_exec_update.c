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
#include "job_control/job_mgr.h"
#include "token/token_mgr.h"
#include "twl_logger.h"

static bool			iter_job_fn(void *job_, void *ctx)
{
	t_job	*job;
	int		errno_ret;

	job = job_;
	errno = 0;
	job->end_pid = waitpid(job->pid, &job->status, WNOHANG | WUNTRACED);
	errno_ret = errno;
	LOG_INFO("job waitpid (pid=%d, endpid=%d, errno_ret=%d, ECHILD=%d",
		job->pid, job->end_pid, errno_ret, ECHILD);
	if (job->end_pid == job->pid)
	{
		job_exec_update_status(job);
		if (!shenv_shflag_enabled(shenv_singleton(), "i"))
			return (false);
		if (job_has_terminated(job))
			job_print(job, 0);
		return (job_has_terminated(job));
	}
	else if (job->end_pid == 0 || errno_ret == ECHILD)
	{
		;
	}
	else
	{
        twl_dprintf(2, "waitpid error: %d\n", job->pid);
		exit(EXIT_FAILURE);
	}
	return (false);
	(void)ctx;
}

void				job_mgr_exec_update(t_lst *jobs)
{
	job_mgr_update_sign(jobs);
	twl_lst_remove_if(jobs, iter_job_fn, NULL, job_del_void);
}
