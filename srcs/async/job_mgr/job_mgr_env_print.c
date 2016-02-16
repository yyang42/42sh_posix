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

/*
** $ jobs
** [1]+  Running                 sleep 99999 && echo abc &
** $ jobs -l
** [1]+ 29125 Running                 sleep 99999 && echo abc &
*/

static char			get_next_char(int len, int count)
{
	if (count == len)
		return ("+");
	if (count == len - 1)
		return ("-");
	else
		return (" ");
}

static void			iter_fn(void *job_, void *len_ptr, void *count_ptr_)
{
	t_job			*job;
	int				len;
	int				*count_ptr;

	job = job_;
	len = *(int *)len_ptr;
	count_ptr = count_ptr_;
	twl_printf("[%lld]%s ", job->job_id, get_next_char(len, *count_ptr));
	if (false) // job->pid
		twl_printf("%d", job->pid);
	twl_printf(" %-23s %s\n", job_status_str(job), job->cmd_str);
	(*count_ptr)++;
}

void				job_mgr_env_print(void)
{
	int				len;
	int				count;
	t_lst			*jobs;

	jobs = environment_singleton()->jobs;
	len = twl_lst_len(jobs);
	count = 1;
	twl_lst_iter2(jobs, iter_fn, &len, &count);
}
