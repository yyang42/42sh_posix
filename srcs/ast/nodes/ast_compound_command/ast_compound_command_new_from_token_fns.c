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

#include "openclose/openclose_matcher.h"
#include "ast/nodes/ast_compound_command.h"

t_compound_command_new_from_token_fn	*compound_command_from_token_fns(void)
{
	static t_compound_command_new_from_token_fn	fns[COMPOUND_COMMAND_NBR];
	static bool									is_loaded = false;

	if (is_loaded == false)
	{
		fns[COMPOUND_COMMAND_SUBSHELL] = ast_subshell_new_from_tokens_void;
		fns[COMPOUND_COMMAND_IF_CLAUSE] = ast_if_clause_new_from_tokens_void;
		fns[COMPOUND_COMMAND_FOR_CLAUSE] = ast_for_clause_new_from_tokens_void;
		fns[COMPOUND_COMMAND_WHILE_CLAUSE] = ast_while_clause_new_from_tokens_void;
		fns[COMPOUND_COMMAND_UNTIL_CLAUSE] = ast_until_clause_new_from_tokens_void;
		fns[COMPOUND_COMMAND_BRACE_GROUP] =
			ast_brace_group_new_from_tokens_void;
	}
	return (fns);
}
