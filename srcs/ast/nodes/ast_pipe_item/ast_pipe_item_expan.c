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

#include <ast/nodes/ast_pipe_item.h>

int			ast_pipe_item_expan(t_ast_pipe_item *ast_pipe_item)
{
	t_ast_command *ast_command;

	ast_command = ast_pipe_item->ast_command;
	if (ast_command->command_type == COMMAND_SIMPLE_COMMAND)
	{
		return (ast_simple_command_expan(ast_command->command));
	}
	return (0);
}
