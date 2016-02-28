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

#include "arexp/nodes/arexp_and.h"
#include "arexp/arexp.h"
#include "token/token_mgr.h"

t_arexp_and				*arexp_and_new_from_tokens(t_lst *tokens,
														struct s_arexp *arexp)
{
	t_arexp_and			*and;
	t_arexp_equality	*equality;
	t_token				*token;

	and = arexp_and_new();
	while (42)
	{
		equality = arexp_equality_new_from_tokens(tokens, arexp);
		if (arexp_has_error(arexp))
		{
			arexp_and_del(and);
			arexp_equality_del(equality);
			return (NULL);
		}
		twl_lst_push_back(and->equality, equality);
		token = token_mgr_first(tokens);
		if (!token || token->type != TOK_AREXP_AND)
			break ;
		token = twl_lst_pop(tokens);
		token_del(token);
	}
	return (and);
}
