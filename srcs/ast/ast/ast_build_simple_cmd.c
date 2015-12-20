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

#include "ast/ast.h"

#include "twl_arr.h"
#include "utils.h"

static void			build(t_ast_simple_cmd *cmd, t_ast *ast)
{
	// twl_lst_push(cmd->cmds, ast_cmd_build2(parser));
	// twl_lst_push(cmd->cmds, ast_cmd_new());
	while (parser_remain_len(ast->parser))
	{
		if (!parser_is_simple_cmd_chars(ast->parser))
			break ;
		// if (parser_is_pipe_elem(ast->parser)
		// 	|| parser_is_andor(ast->parser)
		// 	|| parser_is_list_elem(ast->parser)
		// 	|| (parser_cchar(ast->parser) == ')'))
		// 	break ;
		ast->parser->index++;
	}
	// twl_printf("parser %s\n", parser_cstr(ast->parser));
	(void)cmd;
}

t_ast_simple_cmd			*ast_build_simple_cmd(t_ast *ast)
{
	t_ast_simple_cmd		*simple_cmd;

	simple_cmd = ast_simple_cmd_new();
	simple_cmd->index = ast->parser->index;
	build(simple_cmd, ast);
	return (simple_cmd);
}
