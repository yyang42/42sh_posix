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
	min = edit->copast->start_index > edit->copast->stop_index ? edit->copast->stop_index : edit->copast->start_index;
	max = edit->copast->start_index > edit->copast->stop_index ? edit->copast->start_index : edit->copast->stop_index;
	slice = twl_lst_slice(edit->letters, min, max);
	slice_new = twl_lst_copy(slice, void_letter_copy);
	twl_lst_insert_lst(edit->letters, edit->index, slice_new);
	free(slice);
	free(slice_new);
	edit->index = edit->index + max - min;
}
