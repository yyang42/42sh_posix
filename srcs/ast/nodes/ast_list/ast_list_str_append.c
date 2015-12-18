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

#include "ast/nodes/ast_list.h"

static void			iter_andor_fn(void *andor, void *lines, void *depth)
{
	twl_lst_push(lines, build_ast_line(*(int *)depth, "ANDOR", ""));
	(void)andor;
}

void				ast_list_str_append(t_ast_list *this, t_lst *lines,
																int *depth)
{
	twl_lst_push(lines, build_ast_line(*depth, "LIST", ""));
	twl_lst_iter2(this->andors, iter_andor_fn, lines, depth);
	(void)this;
	(void)depth;
}
