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

#include "arexp/nodes/arexp_exclusive_or.h"
#include "arexp/arexp.h"
#include "token/token_mgr.h"

t_arexp_exclusive_or		*arexp_exclusive_or_new_from_tokens(t_lst *tokens,
														struct s_arexp *arexp)
{
	t_arexp_exclusive_or	*exclusive_or;
	t_arexp_and				*and;
	t_token					*token;

	exclusive_or = arexp_exclusive_or_new();
	while (42)
	{
		and = arexp_and_new_from_tokens(tokens, arexp);
		if (arexp_has_error(arexp))
		{
			arexp_exclusive_or_del(exclusive_or);
			arexp_and_del(and);
			return (NULL);
		}
		twl_lst_push_back(exclusive_or->and, and);
		token = token_mgr_first(tokens);
		if (!token || token->type != TOK_AREXP_EXC_OR)
			break ;
		token = twl_lst_pop(tokens);
		token_del(token);
	}
	return (exclusive_or);
}
