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

#include "job_control/job_mgr.h"
#include "token/token_mgr.h"
#include "logger.h"

static bool			handle_with_status(t_job *job)
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
	if (job->job_status == JOB_TERMINATED)
	{
		str_status = job_status_str_long(job, true);
		shenv_print_error_printf(shenv_singleton(),
			shenv_get_cur_line(), "%s", str_status);
		free(str_status);
		return (true);
	}
	return (false);
}

static bool			remove_print_fn(void *job_, void *ctx)
{
	t_job	*job;

	job = job_;
	errno = 0;
	job->end_pid = waitpid(job->pid, &job->status, WNOHANG | WUNTRACED);

	LOGGER("[DEBUG] pid: %d endpid: %d", job->pid, job->end_pid);
	LOGGER("[DEBUG] errno: %d ECHILD: %d", errno, ECHILD);

	if (job->end_pid == job->pid)
	{
		return (handle_with_status(job));
	}
	else if (job->end_pid == 0 || errno == ECHILD)
	{
		if (job->job_status != JOB_STOPPED)
			job->job_status = JOB_RUNNING;
	}
	else
	{
        twl_dprintf(2, "waitpid error: %d\n", job->pid);
		// exit(EXIT_FAILURE);
	}
	return (false);
	(void)ctx;
}

void				job_mgr_exec_update(t_lst *jobs)
{
	LOGGER("update jobs");
	twl_lst_remove_if(jobs, remove_print_fn, NULL, job_del_void);
}
