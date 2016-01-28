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

void				edit_start_stop_cpy(void *_edit)
{
	t_edit			*edit;

	edit = _edit;
	if (edit->state == SEARCH)
		return ;
	if (edit->copast == NULL)
	{
<<<<<<< 26612ca8cdec31f01c4a596d5df1d615262e430d
		edit->copast = copast_new(edit->index);
	}
	else if (edit->copast->has_copy)
	{
		copast_del(edit->copast);
		edit->copast = copast_new(edit->index);

	}
=======
>>>>>>> line_edition_final: [WIP] copy / paste vim mode - error handling todo
		edit->copast = copast_new(edit->index);
	}
	else if (edit->copast->has_copy)
	{
		copast_del(edit->copast);
		edit->copast = copast_new(edit->index);

	}
	else
	{
		copast_stop_copy(edit->copast, edit->index, edit->letters);
	}
}
