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


#include "twl_ctype.h"

#include "edit/edit.h"

void				edit_handle_printable(t_edit *edit, int key)
{
	char			*tmp_str;


	if (!twl_isprint(key))
		return ;
	letter_mgr_add(edit->letters, letter_new(key), edit->index);
	edit->index++;
	if (edit->state == SEARCH)
	{
		edit->history->search_index = 0;
		if (edit->history->match != NULL)
			twl_lst_del(edit->history->match, NULL);
		tmp_str = letter_mgr_concat_string(edit->letters);
		tmp_str = twl_strtrim_free(tmp_str);
		edit->history->match = history_mgr_find_match(edit->history->history, tmp_str);
	}
}
