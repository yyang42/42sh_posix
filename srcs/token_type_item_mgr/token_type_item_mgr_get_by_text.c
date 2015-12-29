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

#include "token_type_item_mgr.h"

static bool			find_fn(void *item_, void *text)
{
	t_token_type_item	*item;

	item = item_;
	return (twl_strequ(item->text, text));
}

t_token_type_item		*token_type_item_mgr_get_by_text(t_lst *token_type_items, char *text)
{
	return (twl_lst_find(token_type_items, find_fn, text));
}
