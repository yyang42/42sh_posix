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

#include "ast/nodes/ast_assignment.h"

static void			iter_assignment_rec_fn(void *ast_assignment, void *depth_ptr)
{
	ast_assignment_print_rec(ast_assignment, *(int *)depth_ptr);
}

void				ast_assignment_print_rec_list(t_lst *assignment_items, int depth)
{
	twl_lst_iter(assignment_items, iter_assignment_rec_fn, &depth);
}
