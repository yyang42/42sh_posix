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

#include "builtin/cmds/builtin_wait.h"

static bool			find_running_fn(void *job_, void *ctx)
{
	t_job			*job;

	job = job_;
	return (job->job_status == JOB_RUNNING);
	(void)ctx;
}

void				builtin_wait_exec_wait_all(void)
{
	t_lst			*jobs;

	jobs = twl_lst_findall(shenv_singleton()->jobs, find_running_fn, NULL);
	while (twl_lst_len(jobs))
	{
		builtin_wait_put_job_in_wait(twl_lst_first(jobs));
		twl_lst_pop_front(jobs);
	}
	twl_lst_del(jobs, NULL);
}
