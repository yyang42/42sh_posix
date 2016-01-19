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

static void			*void_letter_copy(void *letter)
{
	return (letter_cpy(letter));
}

void				edit_paste_clip(void *_edit)
{
	t_edit			*edit;
	t_lst			*slice;
	t_lst			*slice_new;
	int				max;
	int				min;

	edit = _edit;
	letter_mgr_debug_print(edit->copast->clip);
	twl_lst_insert_lst(edit->letters, edit->index, twl_lst_copy(edit->copast->clip, letter_copy_void));
	edit->index = edit->index + edit->copast->inc_index;
	letters_mgr_insert_clip(edit->letters, edit->index, edit->copast->clipboard_letters);
}
