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
#include "logger.h"

static void			print_terminated_job(t_job *job, char *str_status)
{
	if (job_has_terminated(job))
	{
		shenv_print_error_printf(shenv_singleton(),
			shenv_get_cur_line(), "%s", str_status);
	}
}

static void			handle_with_status(t_job *job)
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
	LOGGER_INFO("job %d status: %s ", job->job_id, str_status);
	free(str_status);
	(void)print_terminated_job;
}

static void			iter_job_fn(void *job_)
{
	t_job	*job;
	int		errno_ret;

	job = job_;
	errno = 0;
	job->end_pid = waitpid(job->pid, &job->status, WNOHANG | WUNTRACED);
	errno_ret = errno;
	LOGGER_INFO("job waitpid (pid=%d, endpid=%d, errno_ret=%d, ECHILD=%d",
		job->pid, job->end_pid, errno_ret, ECHILD);
	if (job->end_pid == job->pid)
	{
		handle_with_status(job);
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
}

void				job_mgr_exec_update(t_lst *jobs)
{
	LOGGER_INFO("update jobs");
	twl_lst_iter0(jobs, iter_job_fn);
}
