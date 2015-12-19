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

static void			build(t_ast_cmd_simple *cmd, t_ast *ast)
{
	// twl_lst_push(cmd->cmds, ast_cmd_build2(parser));
	// twl_lst_push(cmd->cmds, ast_cmd_new());
	twl_printf("== ast->parser {%s}\n", parser_cstr(ast->parser));
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
	(void)cmd;
}

t_ast_cmd_simple			*ast_build_cmd_simple(t_ast *ast)
{
	t_ast_cmd_simple		*cmd_simple;

	COUCOU;
	cmd_simple = ast_cmd_simple_new();
	COUCOU;
	cmd_simple->index = ast->parser->index;
	COUCOU;
	build(cmd_simple, ast);
	COUCOU;
	return (cmd_simple);
}
