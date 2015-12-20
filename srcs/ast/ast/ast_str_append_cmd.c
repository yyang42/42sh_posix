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

void				ast_str_append_cmd(t_ast *ast, t_ast_cmd *cmd)
{
	if (ast_node_get_type(cmd) == AST_COMP_CMD)
		ast_str_append_comp_cmd(ast, cmd);
	else if (ast_node_get_type(cmd) == AST_SIMPLE_CMD)
		ast_str_append_simple_cmd(ast, cmd);
}
