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

t_ast_cmd_subshell			*ast_build_cmd_subshell(t_ast *ast)
{
	t_ast_cmd_subshell		*cmd_subshell;

	cmd_subshell = ast_cmd_subshell_new();
	ast->parser->index++;
	cmd_subshell->index = ast->parser->index;
	cmd_subshell->list = ast_build_list(ast);
	if (parser_cchar(ast->parser) != ')')
	{
		twl_xprintf("[ERROR] Expected ')' but found : %1s",
			parser_cstr(ast->parser));
	}
	ast->parser->index++;
	return (cmd_subshell);
}
