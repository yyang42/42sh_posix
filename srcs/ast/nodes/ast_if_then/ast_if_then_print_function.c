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

#include "ast/nodes/ast_if_then.h"
#include "ast/nodes/ast_compound_list.h"

bool				g_if_then_last_semi_colon = false;
bool				g_is_first_ast_if_then = false;

void				ast_if_then_print_function(t_ast_if_then *ast_if_then,
															int depth)
{
	twl_putstr("if ");
	g_if_then_last_semi_colon = false;
	g_is_first_ast_if_then = true;
	ast_compound_list_print_function(ast_if_then->cond_compound, depth);
	g_is_first_ast_if_then = false;
	if (g_if_then_last_semi_colon)
		twl_putstr("; then");
	else
		twl_putstr(" then");
	g_if_then_last_semi_colon = false;
	ast_compound_list_print_function(ast_if_then->then_compound, depth + 1);
	if (g_if_then_last_semi_colon)
		twl_putstr(";");
	g_if_then_last_semi_colon = false;
}
