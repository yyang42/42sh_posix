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
#include "ast/nodes/ast_redir.h"
#include "ast/nodes/ast_simple_command.h"

static void			iter_fn(void *data, void *next, void *ctx)
{
	twl_putstr(((t_token *)data)->text);
	if (next)
	{
		twl_putchar(' ');
	}
	(void)ctx;
}

void				ast_simple_command_print_function(t_ast_simple_command *this,
																	int depth)
{
	twl_lst_itern(this->cmd_tokens_deep_copy, iter_fn, NULL);
	(void)depth;
//	ast_redir_print_rec_list(this->redir_items, depth);
//	ast_assignment_print_rec_list(this->assignment_items, depth);
}
