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

t_job 				*job_mgr_find_by_pid_perc_job_id(t_lst *jobs, char *str)
{
	t_job			*job;

	if (*str == '%')
	{
		job = job_mgr_find_by_job_id(jobs, str + 1);
	}
	else
	{
		job = job_mgr_find_by_str_pid(jobs, str);
	}
	return (job);
}
