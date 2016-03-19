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

static char			*get_next_char(int len)
{
	char			*sign_str;

	if (len == 0)
		sign_str = "+";
	else if (len == 1)
		sign_str = "-";
	else
		sign_str = " ";
	return (sign_str);
}

void				builtin_jobs_exec_print(t_lst *jobs, int flags)
{
	t_lst			*jobs_copy;
	t_job			*job;
	char			*full_status;

	jobs_copy = twl_lst_copy(jobs, NULL);
	while ((job = twl_lst_pop_front(jobs_copy)))
	{
		if (flags & BUILTIN_JOBS_FLAG_OPT_P)
		{
			twl_printf("%d\n", job->pid);
		}
		else
		{
			twl_printf("[%lld]%s ", job->job_id, get_next_char(twl_lst_len(jobs_copy)));
			if (!flags & BUILTIN_JOBS_FLAG_OPT_L)
				twl_printf(" ");
			full_status = job_status_str_long(job, flags & BUILTIN_JOBS_FLAG_OPT_L);
			twl_printf("%s\n", full_status);
			free(full_status);
		}
	}
	twl_lst_del(jobs_copy, NULL);
}
