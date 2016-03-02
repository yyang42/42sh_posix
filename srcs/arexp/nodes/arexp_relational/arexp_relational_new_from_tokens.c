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

#include "arexp/nodes/arexp_relational.h"
#include "arexp/arexp.h"
#include "token/token_mgr.h"

static bool				is_relational_token(t_token *token)
{
	return (token &&
			(token->type == TOK_AREXP_LESS ||
			 token->type == TOK_AREXP_GREAT ||
			 token->type == TOK_AREXP_LESS_EQ ||
			 token->type == TOK_AREXP_GREAT_EQ));
}

static bool				push_fn(t_lst *tokens, t_arexp_relational *relational,
														t_arexp_shift *shift)
{
	t_arexp_relational__	*to_push;

	to_push = twl_malloc_x0(sizeof(t_arexp_relational__));
	to_push->shift = shift;
	if (!is_relational_token(token_mgr_first(tokens)))
	{
		twl_lst_push(relational->shift, to_push);
		return (false);
	}
	to_push->relational_sign = twl_lst_pop_front(tokens);
	twl_lst_push(relational->shift, to_push);
	return (true);
}

t_arexp_relational		*arexp_relational_new_from_tokens(t_lst *tokens)
{
	t_arexp_relational	*relational;
	t_arexp_shift		*shift;

	relational = arexp_relational_new();
	while (42)
	{
		shift = arexp_shift_new_from_tokens(tokens);
		if (arexp_has_error(arexp_singleton(NULL, false)))
		{
			arexp_relational_del(relational);
			arexp_shift_del(shift);
			return (NULL);
		}
		if (!push_fn(tokens, relational, shift))
			break ;
	}
	return (relational);
}
