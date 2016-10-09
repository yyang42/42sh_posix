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

static bool			find_by_memid_fn(void *job, void *memid)
{
	return (job == memid);
}

t_job				*job_mgr_find_by_memid(t_lst *jobs, void *memid)
{
	return (twl_lst_find(jobs, find_by_memid_fn, memid));
}
