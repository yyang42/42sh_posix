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

#include "builtin/cmds/builtin_env.h"
#include "ast/ast.h"


static int			exec_remaining_command(t_lst *tokens)
{
	int				exit_code;

	if (token_mgr_first_equ(tokens, "-i"))
	{
		twl_lst_pop_front(tokens);
		exit_code = ast_exec_tokens_with_fork(tokens);
	}
	else
	{
		exit_code = ast_exec_tokens(tokens);
	}
	return (exit_code);
}

void				builtin_env_exec(t_lst *tokens, t_shenv *env)
{
	int				exit_code;

	twl_lst_pop_front(tokens);
	if (twl_lst_len(tokens) == 0)
	{
		shenv_print(env);
		exit_code = 0;
	}
	else
	{
		exit_code = exec_remaining_command(tokens);
	}
	(void)exit_code;
	return ; // exit_code
}
