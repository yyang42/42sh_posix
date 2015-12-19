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

#include "ast/nodes/ast_andor.h"
#include "ast/nodes/ast_pipe.h"

static void			iter_andor_fn(void *andor, void *lines, void *depth)
{
	ast_pipe_str_append(andor, lines, depth);
}

void				ast_andor_str_append(t_ast_andor *this, t_lst *lines,
																int *depth_)
{
	int				depth;

	twl_lst_push(lines, build_ast_line(*depth_, "ANDOR_SEQ", ""));
	depth = *depth_ + 1;
	twl_lst_iter2(this->pipes, iter_andor_fn, lines, &depth);
	(void)this;
	(void)depth;
}
