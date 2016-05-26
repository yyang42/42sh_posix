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

#include "ast/nodes/ast_command.h"

void				ast_command_del(t_ast_command *ast_command)
{
	if (!ast_command)
		return ;
	if (ast_command->command)
	{
		if (ast_command->command_type == COMMAND_COMPOUND_COMMAND)
			ast_compound_command_del(ast_command->command);
		else if (ast_command->command_type == COMMAND_SIMPLE_COMMAND)
			ast_simple_command_del(ast_command->command);
		else if (ast_command->command_type == COMMAND_FUNCTION_DEF)
			ast_function_def_del(ast_command->command);
	}
	free(ast_command);
}
