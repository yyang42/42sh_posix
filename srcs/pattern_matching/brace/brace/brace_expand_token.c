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

#include "pattern_matching/brace/brace.h"

static void		iter_fn(void *data, void *ctx1, void *ctx2)
{
	t_token		*copy;

	copy = token_copy(ctx2);
	if (copy->text_unexpanded)
		free(copy->text_unexpanded);
	copy->text_unexpanded = data;
	twl_lst_push_front(ctx1, copy);
}

t_lst			*brace_expand_token(t_token *token)
{
	t_lst		*ret;
	t_lst		*expand;

	ret = twl_lst_new();
	expand = brace_expand(token->text_unexpanded);
	twl_lst_iter2(expand, iter_fn, ret, token);
	twl_lst_del(expand, NULL);
	twl_lst_rev(ret);
	return (ret);
}
