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

#include "ast/nodes/ast_redir.h"

static void			iter_redir_rec_fn(void *ast_redir, void *depth_ptr)
{
	ast_redir_print_rec(ast_redir, *(int *)depth_ptr);
}

void				ast_redir_print_rec_list(t_lst *redir_items, int depth)
{
	twl_lst_iter(redir_items, iter_redir_rec_fn, &depth);
}
