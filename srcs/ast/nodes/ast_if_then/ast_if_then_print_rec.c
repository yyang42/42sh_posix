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

void				ast_if_then_print_rec(t_ast_if_then *ast_if_then, int depth)
{
	ast_print_indent(depth);
	twl_printf("ast_if_then\n");
	depth++;
	ast_compound_list_print_rec(ast_if_then->cond_compound, depth);
	ast_compound_list_print_rec(ast_if_then->then_compound, depth);
}
