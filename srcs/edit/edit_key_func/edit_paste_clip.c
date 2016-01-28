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

#include "edit/edit.h"



void				edit_paste_clip(void *_edit)
{
	t_edit			*edit;

	edit = _edit;
	if (edit->state == SEARCH)
		return ;
	letter_mgr_debug_print(edit->copast->clip);
	twl_lst_insert_lst(edit->letters, edit->index, twl_lst_copy(edit->copast->clip, letter_copy_void));
	edit->index = edit->index + edit->copast->inc_index;
}
