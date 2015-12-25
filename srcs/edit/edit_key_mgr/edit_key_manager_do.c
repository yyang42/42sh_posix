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

#include "edit/edit_key_mgr.h"

static bool			find_fn(void *_edit_key, void *_key)
{
	t_edit_key		*edit_key;
	int				key;

	edit_key = _edit_key;
	key = *((int *)_key);
	if (edit_key->key == key)
		return true;
	return false;
}


void				edit_key_mgr_do(t_lst *edit_keys, void *edit, int key)
{
	t_edit_key		*edit_key;

	edit_key = twl_lst_find(edit_keys, find_fn, &key);
	if (edit_key)
	{
		edit_key->func(edit);
	}
}
