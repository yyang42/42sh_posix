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
#include "twl_logger.h"

static bool			iter_job_fn(void *job, void *ctx)
{
	return (job_wait_update(job));
	(void)ctx;
}

void				job_mgr_wait_update(t_lst *jobs)
{
	job_mgr_update_sign(jobs);
	twl_lst_remove_if(jobs, iter_job_fn, NULL, job_del_void);
}
