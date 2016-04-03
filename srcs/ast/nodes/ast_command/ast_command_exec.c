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

void				ast_command_exec(t_ast_command *this)
{
	if (this->command_type == COMMAND_SIMPLE_COMMAND)
	{
		ast_simple_command_exec(this->command);
	}
	else if (this->command_type == COMMAND_COMPOUND_COMMAND)
	{
		ast_compound_command_exec(this->command);
	}
	else if (this->command_type == COMMAND_FUNCTION_DEF)
	{
		ast_function_def_exec(this->command);
	}
	else
	{
		LOGGER_ERROR("wrong command type");
	}
}
