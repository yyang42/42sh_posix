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

#include "arexp/nodes/arexp_inclusive_or.h"
#include "arexp/arexp.h"
#include "token/token_mgr.h"

t_arexp_inclusive_or		*arexp_inclusive_or_new_from_tokens(t_lst *tokens)
{
	t_arexp_inclusive_or	*inclusive_or;
	t_arexp_exclusive_or	*exclusive_or;
	t_token					*token;

	inclusive_or = arexp_inclusive_or_new();
	while (42)
	{
		exclusive_or = arexp_exclusive_or_new_from_tokens(tokens);
		if (arexp_has_error(arexp_singleton(NULL, false)))
		{
			arexp_inclusive_or_del(inclusive_or);
			arexp_exclusive_or_del(exclusive_or);
			return (NULL);
		}
		twl_lst_push_back(inclusive_or->exclusive_or, exclusive_or);
		token = token_mgr_first(tokens);
		if (!token || token->type != TOK_AREXP_INC_OR)
			break ;
		token = twl_lst_pop_front(tokens);
		token_del(token);
	}
	return (inclusive_or);
}
