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
#include "ast/nodes/ast_pipe_item.h"
#include "ast/nodes/ast_andor_item.h"
#include "ast/nodes/ast_list_item.h"

static bool			is_compound_command(t_lst *tokens)
{
	t_token			*first;

	first = token_mgr_first(tokens);
	return (twl_strequ(first->text, "(")
		|| twl_strequ(first->text, "if"));
}

t_ast_command	*ast_command_new_from_tokens(t_lst *tokens, struct s_ast *ast)
{
	t_ast_command		*ast_command;

	ast_command = ast_command_new();
	ast_command->tokens = twl_lst_copy(tokens, NULL);
	if (is_compound_command(tokens))
	{
		ast_command->command_type = COMMAND_COMPOUND_COMMAND;
		ast_command->command = ast_compound_command_new_from_tokens(tokens, ast);
		if (ast_command->command == NULL)
			return (NULL);
	}
	else
	{
		ast_command->command_type = COMMAND_SIMPLE_COMMAND;
		ast_command->command = ast_simple_command_new_from_tokens(tokens, ast);
	}
	return (ast_command);
}
