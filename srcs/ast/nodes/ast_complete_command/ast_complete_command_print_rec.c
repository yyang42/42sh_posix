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

void				ast_complete_command_print_rec(
							t_ast_complete_command *ast_complete_command,
							int depth)
{
	ast_print_indent(depth);
	twl_printf("%s\n", "complete_command");
	ast_list_print_rec(ast_complete_command->list, depth + 1);
	(void)depth;
	(void)ast_complete_command;
}
