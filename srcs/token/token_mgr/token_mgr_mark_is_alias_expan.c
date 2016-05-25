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

static void			push_fn(void *str, void *lst)
{
	twl_lst_push_back(lst, twl_strdup(str));
}

static void			mark_is_alias_expan_fn(void *token_, void *source_alias_expans)
{
	t_token	*token;

	token = token_;
	twl_lst_iter(source_alias_expans, push_fn, token->source_alias_expans);
}

void				token_mgr_mark_is_alias_expan(t_lst *tokens, t_lst *source_alias_expans)
{
	twl_lst_iter(tokens, mark_is_alias_expan_fn, source_alias_expans);
}
