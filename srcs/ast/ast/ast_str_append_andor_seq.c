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
#include "ast/nodes/ast_if_clause.h"
#include "ast/nodes/ast_cmd_field.h"
#include "ast/nodes/ast_pipe_seq.h"
#include "ast/nodes/ast_andor_seq.h"
#include "ast/nodes/ast_cmd_sub.h"

static void			iter_fn(void *andor, void *ast)
{
	ast_str_append_pipe(ast, andor);
}

void				ast_str_append_andor_seq(t_ast *ast, t_ast_andor_seq *andor)
{
	ast_str_push_line(ast, "ANDOR_SEQ", andor->index);
	ast->out_depth++;
	twl_lst_iter(andor->pipes, iter_fn, ast);
	ast->out_depth--;
}
