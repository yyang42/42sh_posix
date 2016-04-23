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

static bool			sort_by_id_fn(void *job1_, void *job2_, void *context)
{
	t_job	*job1;
	t_job	*job2;

	job1 = job1_;
	job2 = job2_;
	return (job1->job_id < job2->job_id);
	(void)context;
}

void				job_mgr_sort_by_id(t_lst *jobs)
{
	twl_lst_sort(jobs, sort_by_id_fn, NULL);
}
