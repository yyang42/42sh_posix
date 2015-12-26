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

#include "ast/nodes/ast_separator.h"

void				ast_separator_print_rec(
							t_ast_separator *ast_separator,
							int depth)
{
	ast_print_indent(depth);
	twl_putstr("separator\n");
	if (ast_separator->type == AST_SEPERATOR_NEWLINE_LIST)
	{
		ast_newline_list_print_rec(ast_separator->ast_newline_list, depth + 1);
	}
	else if (ast_separator->type == AST_SEPERATOR_SEPARATOR_OP)
	{
		ast_separator_op_print_rec(ast_separator->ast_separator_op, depth + 1);
		ast_linebreak_print_rec(ast_separator->ast_linebreak, depth + 1);
	}
}
