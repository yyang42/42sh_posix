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

#include "arexp/nodes/arexp_logical_or.h"
#include "arexp/arexp.h"
#include "token/token_mgr.h"

t_arexp_logical_or			*arexp_logical_or_new_from_tokens(t_lst *tokens)
{
	t_arexp_logical_or		*logical_or;
	t_arexp_logical_and		*logical_and;
	t_token					*token;

	logical_or = arexp_logical_or_new();
	while (42)
	{
		logical_and = arexp_logical_and_new_from_tokens(tokens);
		if (arexp_has_error(arexp_singleton(NULL, false)))
		{
			arexp_logical_or_del(logical_or);
			arexp_logical_and_del(logical_and);
			return (NULL);
		}
		twl_lst_push_back(logical_or->logical_and, logical_and);
		token = token_mgr_first(tokens);
		if (!token || token->type != TOK_AREXP_LOGICAL_OR)
			break ;
		token = twl_lst_pop_front(tokens);
		token_del(token);
	}
	return (logical_or);
}
