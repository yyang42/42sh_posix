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
	ast_case_item_print_function(case_item, *(int *)depth_ptr);
}

void				ast_case_clause_print_function(t_ast_case_clause *this,
																	int depth)
{
	twl_printf("case %s in ", this->needle_token->text);
	depth += 1;
	twl_lst_iter(this->case_list, case_list_iter_fn, &depth);
	depth -= 1;
	twl_printf("\n%*cesac", depth * 4, ' ');
}
