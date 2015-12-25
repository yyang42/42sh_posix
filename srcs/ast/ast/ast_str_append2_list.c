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

#include <stdlib.h>

#include "ast/ast.h"

void				ast_str_append2_list(t_ast *ast, t_ast2_list *list)
{
	ast_str_push_line(ast, "list", 0);
	ast->out_depth++;
	// ast_str_append2_list(ast, list->list);
	// twl_lst_iter(list->andors, iter_andor_fn, ast);
	ast->out_depth--;
	// (void)list;
	(void)list;
}
