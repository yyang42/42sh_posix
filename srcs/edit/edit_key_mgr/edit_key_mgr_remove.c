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

void				edit_key_mgr_remove(t_lst *edit_keys, t_edit_key *edit_key)
{
	int				index;

	index = twl_lst_indexof(edit_keys, edit_key);
	if (index == -1)
	{
		assert(!"[ERROR] Object not found!");
	}
	twl_lst_popi(edit_keys, index);
	edit_key_del(edit_key);
}
