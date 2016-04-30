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
#include "token/token_mgr.h"

void				ast_command_print_function(t_ast_command *this, int depth)
{
	if (this->command_type == COMMAND_COMPOUND_COMMAND)
		ast_compound_command_print_function(this->command, depth);
	else if (this->command_type == COMMAND_SIMPLE_COMMAND)
		ast_simple_command_print_function(this->command, depth);
//	else if (this->command_type == COMMAND_FUNCTION_DEF)
//		ast_function_def_print_function(this->command, depth);
}
