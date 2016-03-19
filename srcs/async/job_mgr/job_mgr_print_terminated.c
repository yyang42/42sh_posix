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

#include "async/job_mgr.h"
#include "token/token_mgr.h"

static bool			should_be_removed(t_job *job)
{
	return (WIFSIGNALED(job->status));
}

static bool			remove_print_fn(void *job_, void *ctx)
{
	t_job	*job;
	char	*str_status;

	job = job_;
	job_waitpid_update(job);
	if (job->end_pid == job->pid)
	{
		if (should_be_removed(job))
		{
			str_status = job_status_str_long(job, true);
			shenv_print_error_printf(shenv_singleton(),
				shenv_get_cur_line(), "%s", str_status);
			free(str_status);
			return (true);
		}
	}
	return (false);
	(void)ctx;
}

void				job_mgr_print_terminated(t_lst *jobs)
{
	twl_lst_remove_if(jobs, remove_print_fn, NULL, job_del_void);
}
