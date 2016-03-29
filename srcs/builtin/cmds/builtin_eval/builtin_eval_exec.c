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

#include "builtin/cmds/builtin_eval.h"
#include "ast/ast.h"
#include "ast/nodes/ast_compound_list.h"

void				builtin_eval_exec(t_lst *tokens, t_shenv *env)
{
	t_ast			*ast;
	t_lst			*tokens_copy;
	char			*str;

	tokens_copy = twl_lst_copy(tokens, NULL);
	twl_lst_pop_front(tokens_copy);
	str = token_mgr_strjoin(tokens_copy, " ");
	ast = ast_new(str);
	if (ast->error_msg)
	{
		twl_dprintf(2, "%s\n", ast->error_msg);
		ast_del(ast);
	}
	shenv_singleton()->last_exit_code = ast_exec(ast);
	ast_del(ast);
	(void)env;
}
