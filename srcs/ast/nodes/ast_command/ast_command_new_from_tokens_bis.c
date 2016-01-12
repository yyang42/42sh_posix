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

#include "ast/ast.h"
#include "ast/nodes/ast_command.h"
#include "ast/nodes/ast_pipe_item.h"
#include "ast/nodes/ast_andor_item.h"
#include "ast/nodes/ast_list_item.h"
#include "ast/nodes/ast_compound_command.h"

t_ast_command	*ast_command_new_from_tokens_bis(t_lst *tokens, struct s_ast *ast)
{
	t_ast_command		*ast_command;

	ast_command = ast_command_new();
	if (ast_compound_command_get_type_from_tokens(tokens) ==
		COMPOUND_COMMAND_NONE)
	{
		ast_command->command_type = COMMAND_SIMPLE_COMMAND;
		ast_command->command = ast_simple_command_new_from_tokens_bis(tokens, ast);
	}
	else
	{
		ast_command->command_type = COMMAND_COMPOUND_COMMAND;
		ast_command->command =
			ast_compound_command_new_from_tokens(tokens, ast);
	}
	if (ast_has_error(ast))
	{
		ast_command_del(ast_command);
		return (NULL);
	}
	return (ast_command);
}
