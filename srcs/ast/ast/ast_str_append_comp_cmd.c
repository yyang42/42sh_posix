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

void				ast_str_append_comp_cmd(t_ast *ast, void *cmd_)
{
	t_ast_comp_cmd *cmd;

	cmd = cmd_;
	ast_str_push_line(ast, "COMP_CMD", cmd->index);
	ast->out_depth++;
	ast_str_append_cmd_subshell(ast, cmd->cmd);
	ast->out_depth--;
	(void)ast;
	(void)cmd;
}
