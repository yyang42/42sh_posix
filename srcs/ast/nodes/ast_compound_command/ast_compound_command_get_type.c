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

t_compound_command_type	compound_command_get_type_from_tokens(t_lst *tokens)
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
