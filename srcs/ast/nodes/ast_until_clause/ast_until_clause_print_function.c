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

#include "ast/nodes/ast_until_clause.h"
#include "ast/nodes/ast_compound_list.h"
#include "ast/nodes/ast_if_then.h"

void				ast_until_clause_print_function(t_ast_until_clause *this,
																	int depth)
{
	twl_putstr("until ");
	if (this->cond_compound)
	{
		ast_compound_list_print_function_seplast_unfirst(this->cond_compound,
				depth);
	}
	twl_putstr(" do");
	if (this->do_group)
	{
		ast_compound_list_print_function_seplast(this->do_group, depth + 1);
	}
	twl_printf("\n%*cdone", depth * 4, ' ');
}
