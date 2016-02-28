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

#include "arexp/nodes/arexp_additive.h"
#include "arexp/arexp.h"
#include "token/token_mgr.h"

static bool					is_additive_token(t_token *token)
{
	return (token &&
			(token->type == TOK_AREXP_MINUS ||
			 token->type == TOK_AREXP_PLUS));
}

static bool					push_fn(t_lst *tokens,
						t_arexp_additive *additive,
						t_arexp_multiplicative *multiplicative)
{
	t_arexp_additive__	*to_push;

	to_push = twl_malloc_x0(sizeof(t_arexp_additive__));
	to_push->multiplicative = multiplicative;
	if (!is_additive_token(token_mgr_first(tokens)))
	{
		twl_lst_push(additive->multiplicative, to_push);
		return (false);
	}
	to_push->additive_sign = twl_lst_pop_front(tokens);
	twl_lst_push(additive->multiplicative, to_push);
	return (true);
}

t_arexp_additive			*arexp_additive_new_from_tokens(t_lst *tokens,
														struct s_arexp *arexp)
{
	t_arexp_additive		*additive;
	t_arexp_multiplicative	*multiplicative;

	additive = arexp_additive_new();
	while (42)
	{
		multiplicative = arexp_multiplicative_new_from_tokens(tokens, arexp);
		if (arexp_has_error(arexp))
		{
			arexp_additive_del(additive);
			arexp_multiplicative_del(multiplicative);
			return (NULL);
		}
		if (!push_fn(tokens, additive, multiplicative))
			break ;
	}
	return (additive);
}
