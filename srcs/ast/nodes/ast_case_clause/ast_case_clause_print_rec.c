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

#include "ast/nodes/ast_case_clause.h"
#include "ast/nodes/ast_case_item.h"
#include "ast/nodes/ast_compound_list.h"
#include "ast/nodes/ast_if_then.h"

static void			case_list_iter_fn(void *case_item, void *depth_ptr)
{
	int				depth;

	depth = *(int *)depth_ptr;
	ast_print_indent(depth);
	twl_printf("case_item\n");
	ast_case_item_print_rec(case_item, depth + 1);
	(void)case_item;
}

void				ast_case_clause_print_rec(t_ast_case_clause *this,
	int depth)
{
	ast_print_indent(depth);
	twl_printf("ast_case_clause\n", this->needle_token->text);
	depth++;
	ast_print_indent(depth);
	twl_printf("ast_case_needle (%s)\n", this->needle_token->text);
	ast_print_indent(depth);
	twl_printf("ast_case_list\n");
	depth++;
	twl_lst_iter(this->case_list, case_list_iter_fn, &depth);
}
