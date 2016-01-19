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

t_compound_command_type	ast_compound_command_get_type_from_tokens(t_lst *tokens)
{
	t_token			*first;

	first = token_mgr_first(tokens);
	if (twl_strequ(first->text, "("))
		return (COMPOUND_COMMAND_SUBSHELL);
	else if (first->type == TOKEN_IF)
		return (COMPOUND_COMMAND_IF_CLAUSE);
	else if (first->type == TOKEN_FOR)
		return (COMPOUND_COMMAND_FOR_CLAUSE);
	else if (first->type == TOKEN_WHILE)
		return (COMPOUND_COMMAND_WHILE_CLAUSE);
	else if (first->type == TOKEN_UNTIL)
		return (COMPOUND_COMMAND_UNTIL_CLAUSE);
	else if (first->type == TOKEN_LBRACE)
		return (COMPOUND_COMMAND_BRACE_GROUP);
	return (COMPOUND_COMMAND_NONE);
}
