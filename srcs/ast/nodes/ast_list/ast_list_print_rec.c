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

#include "ast/nodes/ast_list.h"
#include "token_mgr.h"

void				ast_list_print_rec(
							t_ast_list *list,
							int depth)
{
	ast_print_indent(depth);
	depth++;
	twl_putstr("list (");
	token_mgr_print_token_text_by_index(list->tokens, 0);
	twl_putstr(")\n");
	if (list->list)
		ast_list_print_rec(list->list, depth);
	if (list->ast_separator_op)
		ast_separator_op_print_rec(list->ast_separator_op, depth);
}
