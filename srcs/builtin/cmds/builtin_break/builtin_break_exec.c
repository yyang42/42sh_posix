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

#include "builtin/cmds/builtin_break.h"

static void			builtin_break_exec_one_arg(char *str_counter)
{
	int				break_counter;

	if (twl_str_is_pos_num(str_counter))
	{
		break_counter = twl_atoi(str_counter);
		shenv_singleton()->shenv_break_counter = break_counter;
	}
	else
	{
		LOGGER_DEBUG("is not a number");
	}
}

void				builtin_break_exec(t_lst *tokens, t_shenv *env)
{
	env->shenv_cur_token = token_mgr_first(tokens);
	if (twl_lst_len(tokens) == 1)
	{
		builtin_break_exec_one_arg("1");
	}
	else if (twl_lst_len(tokens) == 2)
	{
		builtin_break_exec_one_arg(token_mgr_get(tokens, 1)->text);
	}
	else
	{
		LOGGER_DEBUG("too many args");
	}
}
