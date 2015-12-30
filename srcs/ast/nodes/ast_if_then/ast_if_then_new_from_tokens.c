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

#include "ast/nodes/ast_if_then.h"

t_ast_if_then	*ast_if_then_new_from_tokens(t_lst *tokens)
{
	t_ast_if_then		*ast_if_then;

	ast_if_then = ast_if_then_new();
	ast_if_then->tokens = twl_lst_copy(tokens, NULL);
	return (ast_if_then);
}
