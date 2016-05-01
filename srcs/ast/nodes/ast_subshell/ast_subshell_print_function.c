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

#include "ast/nodes/ast_subshell.h"
#include "ast/nodes/ast_compound_list.h"

bool			g_is_first_ast_subshell = false;

void				ast_subshell_print_function(t_ast_subshell *ast_subshell,
																	int depth)
{
	twl_putstr("( ");
	g_is_first_ast_subshell = true;
	ast_compound_list_print_function(ast_subshell->ast_compound_list, depth);
	g_is_first_ast_subshell = false;
	twl_putstr(" )");
}
