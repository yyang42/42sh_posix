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

#include "twl_stdlib.h"

#include "builtin/cmds/builtin_exit.h"
#include "token/token_mgr.h"
#include "builtin/builtin.h"

static void			exec_exit(int status)
{
	LOGGER("exit(%d)", status);
	exit(status);
}

static void			one_argument_case(t_lst *tokens)
{
	char			*exit_code_str;

	exit_code_str = token_mgr_get(tokens, 1)->text;
	if (twl_str_is_pos_num(exit_code_str))
	{
		exec_exit(twl_atoi(exit_code_str));
	}
	else
	{
		shenv_print_error_printf(shenv_singleton(),
			token_mgr_first(tokens)->line,
			"%s: %s: numeric argument required",
			token_mgr_first(tokens)->text, exit_code_str);
		exec_exit(255);
	}
}

void				builtin_exit_exec(t_lst *tokens, t_shenv *this)
{
	if (twl_lst_len(tokens) == 1)
	{
		exec_exit(0);
	}
	else if (twl_lst_len(tokens) == 2)
	{
		one_argument_case(tokens);
	}
	else if (twl_lst_len(tokens) > 2)
	{
		shenv_print_error_printf(shenv_singleton(),
			token_mgr_first(tokens)->line,
			"%s: too many arguments", token_mgr_first(tokens)->text);
		this->last_exit_code = EXIT_FAILURE;
	}
}
