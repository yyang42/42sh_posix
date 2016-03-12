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

static void			one_argument_case(t_lst *tokens)
{
	char			*exit_code_str;

	exit_code_str = token_mgr_get(tokens, 1)->text;
	if (twl_str_is_pos_num(exit_code_str))
	{
		exit(twl_atoi(exit_code_str));
	}
	else
	{
		twl_dprintf(2, "exit: %s: numeric argument required\n", exit_code_str);
		exit(255);
	}
}

void				builtin_exit_exec(t_lst *tokens, t_shenv *this)
{
	if (twl_lst_len(tokens) == 1)
	{
		exit(0);
	}
	else if (twl_lst_len(tokens) == 2)
	{
		one_argument_case(tokens);
	}
	else if (twl_lst_len(tokens) > 2)
	{
		twl_dprintf(2, "exit: too many arguments\n");
		this->last_exit_code = EXIT_FAILURE;
	}
}
