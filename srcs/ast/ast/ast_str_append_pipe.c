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
#include "ast/nodes/ast_pipe_seq.h"
#include "ast/nodes/ast_cmd_sub.h"

static void			iter_fn(void *pipe, void *ast)
{
	ast_str_append_cmd(ast, pipe);
}

void				ast_str_append_pipe(t_ast *ast, t_ast_pipe_seq *pipe)
{
	ast_str_push_line(ast, "PIPE_SEQ", pipe->index);
	ast->out_depth++;
	twl_lst_iter(pipe->pipes, iter_fn, ast);
	ast->out_depth--;
}
