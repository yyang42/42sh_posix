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

static bool			remove_if_fn(void *job_, void *ctx)
{
	// t_job	*job;

	// job = job_;
	// if (job)
	(void)ctx;
	(void)job_;
	return (true);
}

void				job_mgr_remove_non_running(t_lst *jobs)
{
	twl_lst_remove_if(jobs, remove_if_fn, NULL, job_del_void);
}
