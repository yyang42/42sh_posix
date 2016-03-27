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
		shenv_print_error_printf(shenv_singleton(), shenv_get_cur_line(),
			"bg: %s: no such job", job_str_id);
		shenv_singleton()->last_exit_code = EXIT_FAILURE;
	}
	else
	{
		builtin_bg_put_job_in_bg(job);
	}
}

static void			iter_fn(void *str_token)
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
		twl_lst_push_back(segs, "+");
	twl_lst_iter0(segs, iter_fn);
}
