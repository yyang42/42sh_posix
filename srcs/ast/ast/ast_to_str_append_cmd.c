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

#include <stdlib.h>

#include "ast/ast.h"

static void			iter_fn(void *cmd, void *ast)
{
	// ast_to_str_append_cmd(ast, cmd);
	(void)ast;
	(void)cmd;
}

void				ast_to_str_append_cmd(t_ast *ast, t_ast_cmd *cmd)
{
	ast_to_str_push_line(ast, "CMD", cmd->index);
	ast->out_depth++;
	// twl_lst_iter(cmd->cmds, iter_fn, ast);
	ast->out_depth--;
	(void)ast;
	(void)cmd;
	(void)iter_fn;
}
