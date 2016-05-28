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

int					job_mgr_env_push(t_job *job)
{
	static long long int	job_id = 1;
	t_lst					*jobs;

	jobs = shenv_singleton()->jobs;
	LOG_INFO("job_mgr_env_push: %d", job->pid);
	if (job_mgr_find_by_pid(jobs, job->pid))
	{
		LOG_INFO("job already in list: %d", job->pid);
		return (-1);
	}
	if (job->job_id == 0)
	{
		job->job_id = job_id;
		twl_lst_push_back(jobs, job);
		job_id++;
	}
	else
	{
		twl_lst_push_back(jobs, job);
	}
	return (0);
}
