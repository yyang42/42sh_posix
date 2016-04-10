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

#include "token/token_mgr.h"

static void		iter_fn(void *data, void *ctx1, void *ctx2)
{
	t_token		*to_push;

	to_push = token_copy(ctx2);
	token_set_text(to_push, data);
	twl_lst_push_back(ctx1, to_push);
}

t_lst			*token_mgr_new_from_string_list(t_token *to_cpy, t_lst *str_lst)
{
	t_lst		*new;

	new = twl_lst_new();
	twl_lst_iter2(str_lst, iter_fn, new, to_cpy);
	return (new);
}
