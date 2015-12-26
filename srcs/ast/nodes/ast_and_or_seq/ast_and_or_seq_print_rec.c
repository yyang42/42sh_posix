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

#include "ast/nodes/ast_and_or_seq.h"

static void			iter_fn(void *ast_pipe_seq, void *depth_ptr)
{
	ast_pipe_seq_print_rec(ast_pipe_seq, *(int *)depth_ptr);
}

void				ast_and_or_seq_print_rec(t_ast_and_or_seq *ast_and_or_seq, int depth)
{
	ast_print_indent(depth);
	twl_putstr("ast_and_or_seq\n");
	depth++;
	twl_lst_iter(ast_and_or_seq->ast_pipe_seq_lst, iter_fn, &depth);
}
