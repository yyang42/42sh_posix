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
#include "ast/nodes/ast_function_def.h"

static t_ast_command	*ast_command_new_from_tokens_end(struct s_ast *ast,
		t_ast_command *ast_command)
{
	if (ast_has_error(ast))
	{
		ast_command_del(ast_command);
		return (NULL);
	}
	return (ast_command);
}

t_ast_command			*ast_command_new_from_tokens(t_lst *tokens,
		struct s_ast *ast)
{
	t_ast_command		*ast_command;
	t_command_type		type;

	ast_command = ast_command_new();
	type = ast_command_utils_get_command_type(tokens);
	if (type == COMMAND_COMPOUND_COMMAND)
	{
		ast_command->command_type = COMMAND_COMPOUND_COMMAND;
		ast_command->command = ast_compound_command_new_from_tokens(tokens,
				ast);
	}
	else if (type == COMMAND_FUNCTION_DEF)
	{
		ast_command->command_type = COMMAND_FUNCTION_DEF;
		ast_command->command = ast_function_def_new_from_tokens(tokens, ast);
	}
	else if (type == COMMAND_SIMPLE_COMMAND)
	{
		ast_command->command_type = COMMAND_SIMPLE_COMMAND;
		ast_command->command = ast_simple_command_new_from_tokens(tokens, ast);
	}
	return (ast_command_new_from_tokens_end(ast, ast_command));
}
