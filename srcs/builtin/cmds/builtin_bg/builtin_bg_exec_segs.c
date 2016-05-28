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

#include "builtin/cmds/builtin_bg.h"

static void			exec_job_str_id(char *job_str_id)
{
	t_job			*job;

	job = job_mgr_find_by_job_id(shenv_singleton()->jobs, job_str_id);
	if (!job)
	{
		shenv_singl_error(EXIT_FAILURE, "bg: %s: no such job", job_str_id);
	}
	else
	{
		builtin_bg_put_job_in_bg(job);
	}
}

static void			iter_str_token_fn(void *str_token)
{
	char			*job_str_id;

	job_str_id = str_token;
	if (*job_str_id == '%')
		job_str_id++;
	exec_job_str_id(job_str_id);
}

void				builtin_bg_exec_segs(t_argparser_result *argparser_result)
{
	t_lst			*segs;

	segs = twl_lst_copy(argparser_result->remainders, NULL);
	if (twl_lst_len(segs) == 0)
	{
		if (twl_lst_len(shenv_singleton()->jobs) == 0)
			shenv_singl_error(EXIT_FAILURE, "bg: current: no such job");
		else
			twl_lst_push_back(segs, "+");
	}
	twl_lst_iter0(segs, iter_str_token_fn);
	twl_lst_del(segs, NULL);
}
