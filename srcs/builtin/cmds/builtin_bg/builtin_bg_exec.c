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

static void			exec_job_str_id(char *job_str_id, t_token *cmd_token)
{
	t_job			*job;

	job = job_mgr_find_by_job_id(shenv_singleton()->jobs, job_str_id);
	if (!job)
	{
		shenv_print_error_printf(shenv_singleton(), cmd_token->line,
			"bg: %s: no such job", job_str_id);
		shenv_singleton()->last_exit_code = EXIT_FAILURE;
	}
	else
	{
		builtin_bg_put_job_in_bg(job);
	}
}

void				builtin_bg_exec(t_lst *tokens, t_shenv *shenv)
{
	t_token			*first_token;
	char			*job_str_id;
	t_lst			*tokens_copy;

	tokens_copy = twl_lst_copy(tokens, NULL);
	twl_lst_pop_front(tokens_copy);
	if (twl_lst_len(tokens_copy) == 0)
	{
		job_str_id = "+";
	}
	else
	{
		first_token = token_mgr_first(tokens_copy);
		job_str_id = first_token->text;
		if (*job_str_id == '-' && twl_strlen(job_str_id) > 1)
		{
			builtin_bg_invalid_opt_print_usage(job_str_id + 1, token_mgr_first(tokens));
			shenv_singleton()->last_exit_code = EXIT_FAILURE;
			return ;
		}
		if (*job_str_id == '%')
			job_str_id++;
	}
	exec_job_str_id(job_str_id, token_mgr_first(tokens));
	twl_lst_del(tokens_copy, NULL);
	(void)shenv;
}
