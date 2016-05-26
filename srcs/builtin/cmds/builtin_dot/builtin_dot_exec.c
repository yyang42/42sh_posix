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

#include "builtin/cmds/builtin_dot.h"

void				builtin_dot_exec(t_lst *tokens, t_shenv *env)
{
	t_argparser_result	*argparser_result;

	argparser_result = argparser_parse_tokens(builtin_dot_argparser(), tokens);
	if (argparser_result->err_msg || twl_lst_len(argparser_result->remainders) == 0)
	{
		argparser_result_print_error_with_help(argparser_result);
		env->last_exit_code = 2;
		exit(2);
	}
	else
	{
		builtin_dot_exec_do(twl_lst_first(argparser_result->remainders));
	}
	argparser_result_del(argparser_result);
}
