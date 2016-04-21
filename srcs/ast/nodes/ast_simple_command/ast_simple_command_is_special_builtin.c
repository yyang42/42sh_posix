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

#include "ast/nodes/ast_simple_command.h"
#include "builtin/builtin_mgr.h"
#include "data.h"

bool				ast_simple_command_is_special_builtin(t_ast_simple_command *this)
{
	t_token			*first;

	first = token_mgr_first(this->cmd_tokens_expanded);
	if (!first)
		return (false);
	return (builtin_mgr_is_special_builtin(data_builtins(), first->text));
}
