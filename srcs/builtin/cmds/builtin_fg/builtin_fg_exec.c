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

#include "builtin/cmds/builtin_fg.h"

static void			exec_job_str_id(char *job_str_id)
{
	t_job			*job;

	job = job_mgr_find_by_job_id(shenv_singleton()->jobs, job_str_id);
	if (!job)
	{
		shenv_singl_error(EXIT_FAILURE,
			"fg: %s: no such job", job_str_id);
	}
	else
	{
		builtin_fg_put_job_in_fg(job);
	}
}

void				builtin_fg_exec(t_lst *tokens, t_shenv *shenv)
{
	t_token			*first_arg_token;
	char			*job_str_id;

	if (twl_lst_len(tokens) == 1)
	{
		if (twl_lst_len(shenv_singleton()->jobs) == 0)
		{
			shenv_singl_error(1, "fg: current: no such job");
			return ;
		}
		job_str_id = "+";
	}
	else
	{
		first_arg_token = token_mgr_get(tokens, 1);
		job_str_id = first_arg_token->text;
		if (*job_str_id == '-' && twl_strlen(job_str_id) > 1)
		{
			builtin_fg_invalid_opt_print_usage(job_str_id + 1);
			shenv_singleton()->last_exit_code = EXIT_FAILURE;
			return ;
		}
		if (*job_str_id == '%')
			job_str_id++;
	}
	exec_job_str_id(job_str_id);
	(void)shenv;
}
