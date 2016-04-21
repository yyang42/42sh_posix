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

#include "builtin/cmds/builtin_exec.h"
#include "logger.h"

static void			iter_redir_fn(void *tokens)
{
	int				io_number;
	char			*operator;
	char			*param;

	if (twl_lst_len(tokens) == 3)
	{
		io_number = twl_atoi(token_mgr_get(tokens, 0)->text);
		operator = token_mgr_get(tokens, 1)->text;
		param = token_mgr_get(tokens, 2)->text;
		builtin_exec_redir_exec(io_number, operator, param);
		if (shenv_singleton()->last_exit_code != EXIT_SUCCESS)
			builtin_exec_exit(shenv_singleton()->last_exit_code);
	}
	else
	{
		shenv_singl_error(1, "exec: redir error");
		exit(1);
	}
}

void				builtin_exec_redir_handler(t_lst *redir_tokens_groups)
{
	twl_lst_iter0(redir_tokens_groups, iter_redir_fn);
}
