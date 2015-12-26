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

bool				ast_separator_op_is_own_type(t_lst *tokens)
{
	t_token			*first_token;

	first_token = twl_lst_first(tokens);
	if (first_token
		&& twl_strequ(first_token->text, "&")
		&& twl_strequ(first_token->text, ";"))
	{
		return (true);
	}
	return (true);
}
