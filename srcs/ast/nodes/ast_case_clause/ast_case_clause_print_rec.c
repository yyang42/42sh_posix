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
#include "ast/nodes/ast_compound_list.h"
#include "ast/nodes/ast_if_then.h"

void				ast_case_clause_print_rec(t_ast_case_clause *this,
	int depth)
{
	ast_print_indent(depth);
	twl_printf("ast_case_clause\n");
	depth++;
	if (this->cond_compound)
	{
		ast_print_indent(depth);
		twl_printf("cond_compound\n");
		ast_compound_list_print_rec(this->cond_compound, depth + 1);
	}
	if (this->do_group)
	{
		ast_print_indent(depth);
		twl_printf("do_group\n");
		ast_compound_list_print_rec(this->do_group, depth + 1);
	}
}
