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

#include "builtin/cmds/builtin_trap.h"

void				builtin_trap_exec(t_lst *tokens, t_shenv *shenv)
{
	t_argparser_result *argparser_result;
	t_lst				*token_copy;

	token_copy = twl_lst_copy(tokens, NULL);
	twl_lst_pop_front(token_copy);

	twl_printf("!!! NOT IMPL YET !!!\n");
	trap_mgr_add(shenv->traps, trap_new(token_copy, 42));
	builtin_trap_print(shenv);

	twl_lst_del(token_copy, NULL);
	return ;
	argparser_result = argparser_parse_tokens(builtin_trap_argparser(), tokens);
	shenv->last_exit_code = EXIT_SUCCESS;
	if (argparser_result->err_msg)
	{
		argparser_result_print_error_with_help(argparser_result);
	}
	else
	{
		if (argparser_result_opt_is_set(argparser_result, "p")
			|| twl_lst_len(argparser_result->remainders) == 0)
		{
			builtin_trap_print(shenv);
		}
		else
		{

		}
	}
}
