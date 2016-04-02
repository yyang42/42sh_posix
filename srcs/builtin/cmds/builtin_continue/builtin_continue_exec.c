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

#include "builtin/cmds/builtin_continue.h"

static void			builtin_continue_exec_one_arg(char *str_counter)
{
	int				continue_counter;

	if (twl_str_is_num(str_counter))
	{
		continue_counter = twl_atoi(str_counter);
		if (continue_counter > 0)
		{
			// if (continue_counter > shenv_singleton()->shenv_loop_level)
				// continue_counter = shenv_singleton()->shenv_loop_level;
			shenv_singleton()->shenv_continue_counter = continue_counter;
			LOGGER_INFO("continue: %d", continue_counter);
		}
		else
		{
			shenv_singleton()->shenv_continue_counter = -1;
			shenv_singl_error(EXIT_FAILURE, "continue: %s: loop count out of range", str_counter);
		}
	}
	else
	{
		shenv_singleton()->shenv_continue_counter = -1;
		shenv_singl_error(128, "continue: %s: numeric argument required", str_counter);
		exit(shenv_singleton()->last_exit_code);
	}
}

void				builtin_continue_exec(t_lst *tokens, t_shenv *env)
{
	env->shenv_cur_token = token_mgr_first(tokens);
	if (twl_lst_len(tokens) == 1)
	{
		builtin_continue_exec_one_arg("1");
	}
	else if (twl_lst_len(tokens) == 2)
	{
		builtin_continue_exec_one_arg(token_mgr_get(tokens, 1)->text);
	}
	else
	{
		LOGGER_DEBUG("too many args");
	}
}
