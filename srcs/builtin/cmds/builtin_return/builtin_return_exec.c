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

#include "builtin/cmds/builtin_return.h"

static void			builtin_return_exec_one_arg(char *str_counter)
{
	int				return_counter;

	if (twl_str_is_num(str_counter))
	{
		return_counter = twl_atoi(str_counter);
		if (return_counter >= 0 && return_counter <= 255)
		{
			shenv_singleton()->last_exit_code = return_counter;
		}
		else
		{
			shenv_singl_error(EXIT_FAILURE,
					"return: %s: loop count out of range", str_counter);
		}
	}
	else
	{
		shenv_singl_error(255,
				"return: %s: numeric argument required", str_counter);
	}
}

void				builtin_return_exec(t_lst *tokens, t_shenv *env)
{
	if (!shenv_singleton()->shenv_is_function_or_script)
	{
		shenv_singl_error(EXIT_FAILURE,
				"return: can only `return' from a function or sourced script");
		return ;
	}
	env->shenv_cur_token = token_mgr_first(tokens);
	shenv_singleton()->shenv_return_triggered = true;
	if (twl_lst_len(tokens) == 1)
	{
		LOG_INFO("return");
	}
	else if (twl_lst_len(tokens) == 2)
	{
		LOG_INFO("return: %s", token_mgr_get(tokens, 1)->text);
		builtin_return_exec_one_arg(token_mgr_get(tokens, 1)->text);
	}
	else
	{
		shenv_singl_error(EXIT_FAILURE, "return: too many arguments");
	}
}
