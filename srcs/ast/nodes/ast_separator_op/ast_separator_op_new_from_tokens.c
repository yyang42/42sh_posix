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

#include "ast/nodes/ast_separator_op.h"

t_ast_separator_op	*ast_separator_op_new_from_tokens(t_lst *tokens)
{
	t_ast_separator_op		*ast_separator_op;

	if (!ast_separator_op_is_own_type(tokens))
		return (NULL);
	ast_separator_op = ast_separator_op_new();
	twl_lst_push(ast_separator_op->tokens, twl_lst_shift(tokens));
	return (ast_separator_op);
	(void)tokens;
}
