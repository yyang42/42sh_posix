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

#include "edit/edit_move_mgr.h"

static bool			find_fn(void *_edit_move, void *_key)
{
	t_edit_move		*edit_move;
	int				key;

	edit_move = _edit_move;
	twl_lprintf("here\n");
	key = *((int *)_key);
	if (edit_move->key == key)
		return true;
	return false;
}


void				edit_move_mgr_do(t_lst *edit_moves, void *edit, int key)
{
	t_edit_move		*edit_move;

	edit_move = twl_lst_find(edit_moves, find_fn, &key);
	if (edit_move)
	{
		edit_move->func(edit);
	}
}
