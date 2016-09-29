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
#include "twl_stdlib.h"

static bool			find_by_id_fn(void *job_, void *job_id_ptr)
{
	int				job_id;
	t_job			*job;

	job = job_;
	job_id = *(int *)job_id_ptr;
	return (job->job_id == job_id);
}

t_job				*job_mgr_find_by_job_id(t_lst *jobs, char *job_str_id)
{
	int				job_id;

	if (twl_strequ(job_str_id, "+"))
		job_id = -1;
	else if (twl_strequ(job_str_id, "-"))
		job_id = -2;
	else if (twl_str_is_pos_num(job_str_id))
		job_id = twl_atoi(job_str_id);
	else
		return (NULL);
	if (job_id < 0)
		return (twl_lst_get(jobs, job_id));
	else
		return (twl_lst_find(jobs, find_by_id_fn, &job_id));
}
