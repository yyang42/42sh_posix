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

#include "edit/letter_mgr.h"
#include "edit/edit.h"

void				letter_mgr_delete_prev_word(t_lst *letters, void *edit_)
{
	t_edit			*edit;
	int				start_index;

	edit = edit_;
	start_index = edit->index;
	letter_mgr_move_prev_word(letters, edit);
	while (start_index > edit->index)
	{
		start_index--;
		letter_mgr_remove(letters, start_index);
	}
}
