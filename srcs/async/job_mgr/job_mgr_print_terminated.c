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

static bool			should_be_removed(t_job *job)
{
	return (WIFEXITED(job->status) || WIFSIGNALED(job->status));
}

static bool			remove_print_fn(void *job_, void *ctx)
{
	t_job	*job;
	char	*str_status;

	job = job_;
	COUCOU
	if (job->end_pid == job->pid)
	{
		COUCOU
		if (should_be_removed(job))
		{
			COUCOU
			str_status = job_status_str_long(job, true);
			twl_printf("%s\n", str_status);
			free(str_status);
			COUCOU
			return (true);
		}
	}
			COUCOU
	return (false);
	(void)ctx;
}

void				job_mgr_print_terminated(t_lst *jobs)
{
	COUCOU
	twl_lst_remove_if(jobs, remove_print_fn, NULL, job_del_void);
	(void)remove_print_fn;
	(void)jobs;
	COUCOU
}
