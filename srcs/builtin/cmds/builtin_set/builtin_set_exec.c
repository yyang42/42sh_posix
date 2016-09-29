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

#include "builtin/cmds/builtin_set.h"
#include "twl_unistd.h"
#include "twl_arr.h"

void				builtin_set_exec(t_lst *tokens, t_shenv *env)
{
	t_lst			*tokens_copy;

	tokens_copy = twl_lst_copy(tokens, NULL);
	twl_lst_pop_front(tokens_copy);
	if (twl_lst_len(tokens_copy) == 0)
	{
		builtin_set_exec_print(env);
	}
	else
	{
		if (twl_strequ(token_mgr_get(tokens_copy, 0)->text, "--"))
		{
			shenv_remove_all_pos_params(env);
			if (twl_lst_len(tokens_copy) == 1)
			{
				twl_lst_del(tokens_copy, NULL);
				return ;
			}
		}
	}
	builtin_set_exec_args(tokens);
	twl_lst_del(tokens_copy, NULL);
}
