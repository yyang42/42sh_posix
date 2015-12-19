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

static void			build(t_ast_cmd *cmd, t_ast *ast)
{
	// twl_lst_push(cmd->cmds, ast_cmd_build2(parser));
	twl_lst_push(cmd->cmds, ast_cmd_new());
	while (parser_remain_len(ast->parser))
	{
		if (parser_is_pipe_elem(ast->parser)
			|| parser_is_andor(ast->parser)
			|| parser_is_list_elem(ast->parser))
			break ;
		ast->parser->index++;
	}
}

t_ast_cmd			*ast_build_cmd(t_ast *ast)
{
	t_ast_cmd		*cmd;

	cmd = ast_cmd_new();
	cmd->index = ast->parser->index;
	build(cmd, ast);
	(void)ast->parser;
	(void)build;
	return (cmd);
}
