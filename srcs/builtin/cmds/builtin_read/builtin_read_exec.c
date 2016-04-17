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

#include "builtin/cmds/builtin_read.h"

void				builtin_read_exec(t_lst *tokens, t_shenv *env)
{
	t_argparser_result	*argparser_result;
	t_lst				*remainders;

	env->shenv_cur_token = token_mgr_first(tokens);
	argparser_result = argparser_parse_tokens(builtin_read_argparser(), tokens);
	remainders = argparser_result->remainders;
	if (argparser_result->err_msg)
	{
		argparser_result_print_usage_exit_status(argparser_result, 2);
	}
	else
	{
		builtin_read_exec_readline(argparser_result);
	}
}
