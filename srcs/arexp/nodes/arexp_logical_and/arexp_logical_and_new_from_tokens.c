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

#include "arexp/nodes/arexp_logical_and.h"
#include "arexp/arexp.h"
#include "token/token_mgr.h"

t_arexp_logical_and			*arexp_logical_and_new_from_tokens(t_lst *tokens)
{
	t_arexp_logical_and		*logical_and;
	t_arexp_inclusive_or	*inclusive_or;
	t_token					*token;

	logical_and = arexp_logical_and_new();
	while (42)
	{
		inclusive_or = arexp_inclusive_or_new_from_tokens(tokens);
		if (arexp_has_error(arexp_singleton(NULL, false)))
		{
			arexp_logical_and_del(logical_and);
			arexp_inclusive_or_del(inclusive_or);
			return (NULL);
		}
		twl_lst_push_back(logical_and->inclusive_or, inclusive_or);
		token = token_mgr_first(tokens);
		if (!token || token->type != TOK_AREXP_LOGICAL_AND)
			break ;
		token = twl_lst_pop_front(tokens);
		token_del(token);
	}
	return (logical_and);
}
