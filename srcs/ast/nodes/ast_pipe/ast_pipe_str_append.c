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

#include "ast/nodes/ast_pipe.h"
/*
static void			iter_pipe_fn(void *pipe, void *lines, void *depth)
{
	twl_lst_push(lines, build_ast_line(*(int *)depth, "PIPE", ""));
	(void)pipe;
}
*/
void				ast_pipe_str_append(t_ast_pipe *this, t_lst *lines,
																int *depth)
{
	twl_lst_push(lines, build_ast_line(*depth, "PIPE_SEQ", ""));
	// *depth += 1;
	// twl_lst_iter2(this->pipes, iter_pipe_fn, lines, depth);
	(void)this;
	(void)depth;
}
