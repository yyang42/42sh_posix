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

#include "ast/nodes/ast_compound_command.h"

static t_compound_command_new_from_token_fn * get_new_from_token_fns(void)
{
	static t_compound_command_new_from_token_fn fns[COMPOUND_COMMAND_NBR];

	fns[COMPOUND_COMMAND_SUBSHELL] = ast_subshell_new_from_tokens_void;
	fns[COMPOUND_COMMAND_IF_CLAUSE] = ast_if_clause_new_from_tokens_void;
	return (fns);
}

static t_compound_command_type get_compound_command_type(t_lst *tokens)
{
	t_token			*first;

	first = token_mgr_first(tokens);
	if (twl_strequ(first->text, "("))
	{
		return (COMPOUND_COMMAND_SUBSHELL);
	}
	else if (twl_strequ(first->text, "if"))
	{
		return (COMPOUND_COMMAND_IF_CLAUSE);
	}
	return (COMPOUND_COMMAND_NONE);
}

t_ast_compound_command	*ast_compound_command_new_from_tokens(t_lst *tokens)
{
	t_ast_compound_command		*this;

	this = ast_compound_command_new();
	this->tokens = twl_lst_copy(tokens, NULL);
	this->type = get_compound_command_type(tokens);
	if (this->type != COMPOUND_COMMAND_NONE)
	{
		this->command = get_new_from_token_fns()[this->type](tokens);
	}
	return (this);
	(void)tokens;
}
