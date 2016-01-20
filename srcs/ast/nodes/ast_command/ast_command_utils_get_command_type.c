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
#include "token/token_utils.h"

static bool			is_function(t_lst *tokens)
{
	return (twl_lst_len(tokens) >= 3
		&& token_utils_is_valid_name(token_mgr_get(tokens, 0)->text)
		&& twl_strequ(token_mgr_get(tokens, 1)->text, "(")
		&& twl_strequ(token_mgr_get(tokens, 2)->text, ")")
		);
}

t_command_type		ast_command_utils_get_command_type(t_lst *tokens)
{
	if (is_function(tokens))
		return (COMMAND_FUNCTION_DEF);
	if (ast_compound_command_get_type_from_tokens(tokens) != COMPOUND_COMMAND_NONE)
		return (COMMAND_COMPOUND_COMMAND);
	return (COMMAND_SIMPLE_COMMAND);
}
