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

static bool			find_by_pid_fn(void *job_, void *pid_ptr)
{
	int				pid;
	t_job			*job;

	job = job_;
	pid = *(int *)pid_ptr;
	return (job->pid == pid);
}

t_job 				*job_mgr_find_by_pid(t_lst *jobs, int pid)
{
	return (twl_lst_find(jobs, find_by_pid_fn, &pid));
}
