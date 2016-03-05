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

int					builtin_eval_exec(t_lst *tokens, t_shenv *env)
{
	t_ast			*ast;
	int				ret;
	char				*str;

	str = token_mgr_strjoin(tokens, " "); // TODO: refactor
	(void)env;
	ast = ast_new(&str[5]);
	if (ast->error_msg)
	{
		twl_dprintf(2, "%s\n", ast->error_msg);
		ast_del(ast);
		return (1);
	}
	ret = ast_exec(ast);
	ast_del(ast);
	return (ret);
}
