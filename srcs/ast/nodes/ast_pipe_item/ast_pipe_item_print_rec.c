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

#include "ast/nodes/ast_pipe_item.h"

void				ast_pipe_item_print_rec(t_ast_pipe_item *ast_pipe_item, int depth)
{
	ast_print_indent(depth);
	twl_putstr("ast_pipe_item");
	if (ast_pipe_item->separator)
		twl_printf_escape_nl(" (sep=%s)", ast_pipe_item->separator->text);
	twl_putstr("\n");
	depth++;
	ast_command_print_rec(ast_pipe_item->ast_command, depth);
}
