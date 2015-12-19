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

#include "ast/nodes/ast_node.h"
#include "ast/nodes/ast_if.h"
#include "ast/nodes/ast_cmd_field.h"
#include "ast/nodes/ast_pipe.h"
#include "ast/nodes/ast_andor.h"
#include "ast/nodes/ast_cmd_sub.h"

static void			iter_andor_fn(void *andor, void *ast)
{
	ast_to_str_append_andor(ast, andor);
}

void				ast_to_str_append_list(t_ast *ast, t_ast_list *list)
{
	ast_to_str_push_line(ast, "LIST", list->index);
	ast->out_depth++;
	twl_lst_iter(list->andors, iter_andor_fn, ast);
	ast->out_depth--;
	(void)list;
}
