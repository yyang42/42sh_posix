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

#include "builtin/cmds/builtin_jobs.h"

void				builtin_jobs_exec_print(t_lst *jobs, int flags)
{
	t_lst			*jobs_copy;
	t_job			*job;

	job_mgr_sort_by_status(jobs);
	job_mgr_update_sign(jobs);
	job_mgr_sort_by_id(jobs);
	jobs_copy = twl_lst_copy(jobs, NULL);
	while ((job = twl_lst_pop_front(jobs_copy)))
	{
		job_print(job, flags);
		if (job_has_terminated(job))
			job_mgr_remove(jobs, job);
	}
	twl_lst_del(jobs_copy, NULL);
}
