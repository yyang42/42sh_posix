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

#include "ast/nodes/ast_brace_group.h"
#include "ast/nodes/ast_compound_list.h"

void				ast_brace_group_print_rec(t_ast_brace_group *ast_brace_group, int depth)
{
	ast_print_indent(depth);
	twl_printf("ast_brace_group\n");
	depth++;
	ast_compound_list_print_rec(ast_brace_group->ast_compound_list, depth);
}
