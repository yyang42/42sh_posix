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

#include "builtin/cmds/builtin_exec.h"
#include "file.h"
#include "twl_logger.h"

static void			del_token_group_fn(void *token_group)
{
	twl_lst_del(token_group, NULL);
}

static void			builtin_exec_exec_do(t_lst *tokens)
{
	t_argparser_result	*argparser_result;

	argparser_result = argparser_parse_tokens(builtin_exec_argparser(), tokens);
	if (argparser_result->err_msg)
	{
		argparser_result_print_usage_exit_status(argparser_result, 2);
	}
	else
	{
		if (twl_lst_len(argparser_result->remainders))
		{
			shenv_execve_findpath(shenv_singleton(), argparser_result->remainders);
		}
	}
	argparser_result_del(argparser_result);
}

void				builtin_exec_exec(t_lst *tokens, t_shenv *env)
{
	t_lst			*redir_tokens_groups;
	t_lst			*remaining_of_redir_tokens;

	env->shenv_cur_token = token_mgr_first(tokens);
	remaining_of_redir_tokens = twl_lst_new();
	redir_tokens_groups = token_mgr_extract_redir(tokens, remaining_of_redir_tokens);
	builtin_exec_redir_handler(redir_tokens_groups);
	builtin_exec_exec_do(remaining_of_redir_tokens);
	twl_lst_iter0(redir_tokens_groups, del_token_group_fn);
	twl_lst_del(redir_tokens_groups, NULL);
	twl_lst_del(remaining_of_redir_tokens, NULL);
}
