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

#include "ast/nodes/ast_complete_command.h"

static void			iter_fn(void *ast_and_or_seq, void *depth_ptr)
{
	ast_and_or_seq_print_rec(ast_and_or_seq, *(int *)depth_ptr);
}

void				ast_complete_command_print_rec(
							t_ast_complete_command *ast_complete_command,
							int depth)
{
	ast_print_indent(depth);
	twl_putstr("complete_command\n");
	depth++;
	twl_lst_iter(ast_complete_command->ast_and_or_seq_lst, iter_fn, &depth);
}
