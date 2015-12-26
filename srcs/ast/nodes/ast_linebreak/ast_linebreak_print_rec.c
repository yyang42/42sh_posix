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

#include "ast/nodes/ast_linebreak.h"

void				ast_linebreak_print_rec(t_ast_linebreak *ast_linebreak, int depth)
{
	ast_print_indent(depth);
	twl_putstr("ast_linebreak\n");
	if (ast_linebreak->ast_newline_list)
	{
		ast_newline_list_print_rec(ast_linebreak->ast_newline_list, depth + 1);
	}
	(void)ast_linebreak;
}
