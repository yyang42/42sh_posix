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

static void			assign_iter_fn(void *data, void *prev, void *ctx)
{
	ast_assignment_print_function(data);
	if (prev)
	{
		twl_putchar(' ');
	}
	*(bool *)ctx = true;
}

static void			command_iter_fn(void *data, void *next, void *ctx)
{
	twl_putstr(((t_token *)data)->text);
	if (next)
	{
		twl_putchar(' ');
	}
	*(bool *)ctx = true;
}

void				ast_simple_command_print_function(
									t_ast_simple_command *this, int depth)
{
	bool			is_prev_set;

	is_prev_set = false;
	twl_lst_itern(this->assignment_items, assign_iter_fn, &is_prev_set);
	if (is_prev_set && twl_lst_len(this->cmd_tokens_deep_copy))
		twl_putchar(' ');
	twl_lst_itern(this->cmd_tokens_deep_copy, command_iter_fn, &is_prev_set);
	if (is_prev_set && twl_lst_len(this->redir_items))
		twl_putchar(' ');
	ast_redir_print_function_list(this->redir_items);
	(void)depth;
}
