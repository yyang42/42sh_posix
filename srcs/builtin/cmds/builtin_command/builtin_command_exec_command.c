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

#include "builtin/cmds/builtin_command.h"
#include "builtin/builtin_mgr.h"
#include "data.h"

//static void		wrapper_iter_fn(void *data, void *ctx1, void *ctx2)
//{
//	t_token		*new;
//
//	new = token_copy(ctx2);
//	token_set_text(new, data);
//	twl_printf("%s\n", data);
//	twl_lst_push_back(ctx1, new);
//}

void			builtin_command_exec_command(t_lst *tokens,
												t_argparser_result *result,
												t_shenv *shenv)
{
	t_builtin	*builtin;
	char		*cmd_name;

	//wrapper = twl_lst_new();
	//twl_lst_iter2(result->remainders, wrapper_iter_fn, wrapper,
	//													twl_lst_first(tokens));
	cmd_name = twl_lst_first(result->remainders);
	(void)tokens;
	//twl_printf("->%s<-\n", cmd_name);
	builtin = builtin_mgr_find_by_name(data_builtins(), cmd_name);
	if (builtin)
		builtin->builtin_fn(result->remainders, shenv);
	else
		ast_simple_command_execve(result->remainders, result->remainders);
}
