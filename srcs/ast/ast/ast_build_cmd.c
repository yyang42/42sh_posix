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

#include "twl_xstring.h"

#include "ast/ast.h"
#include "ast/nodes/ast_cmd.h"
#include "ast/nodes/ast_cmd_subshell.h"

void				*ast_build_cmd(t_ast *ast)
{
	void		*cmd;

	if (parser_is_subshell(ast->parser))
	{
		cmd = ast_build_cmd_subshell(ast);
	}
	else
	{
		cmd = ast_build_simple_cmd(ast);
	}
	// cmd->index = ast->parser->index;
	// build(cmd, ast);
	return (cmd);
}
