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

#include "builtin/cmds/builtin_getopts.h"

void				builtin_getopts_exec(t_lst *tokens, t_shenv *env)
{
	t_argparser_result	*argparser_result;

	twl_printf("NOT IMPLEMENTED\n");
	argparser_result = argparser_parse_tokens(builtin_getopts_argparser(), tokens);
	if (argparser_result->err_msg)
	{
		argparser_result_print_error_with_help(argparser_result);
		env->last_exit_code = 2;
	}
	else
	{
		 // || twl_lst_len(argparser_result->remainders) == 0
		;
	}
}
