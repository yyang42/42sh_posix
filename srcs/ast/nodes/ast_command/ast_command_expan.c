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

int					ast_command_expan(t_ast_command *this)
{
	int				ret;

	ret = 1;
	if (this->command_type == COMMAND_SIMPLE_COMMAND)
		ret = ast_simple_command_expan(this->command);
	// else if (this->command_type == COMMAND_COMPOUND_COMMAND)
	// 	ret = ast_compound_command_expan(this->command);
	// else if (this->command_type == COMMAND_FUNCTION_DEF)
	// 	return (ast_function_def_expan(this->command));
	return (ret);
}
