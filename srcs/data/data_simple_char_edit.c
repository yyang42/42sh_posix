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

#include "data.h"
#include "edit/edit.h"
#include "edit/simple_char.h"

static t_simple_char	*sc_new(char c, void (*fn)(t_edit *))
{
	return (simple_char_new(c, fn));
}

t_lst					*data_simple_char_edit(void)
{
	static t_lst		*data = NULL;

	if (!data)
	{
		data = twl_lst_new();
		twl_lst_push_front(data, sc_new('\001', edit_move_home));
		twl_lst_push_front(data, sc_new('\002', edit_move_left));
		twl_lst_push_front(data, sc_new('\004', edit_del_right));
		twl_lst_push_front(data, sc_new('\005', edit_move_end));
		twl_lst_push_front(data, sc_new('\006', edit_move_right));
		twl_lst_push_front(data, sc_new('\011', edit_completion));
		twl_lst_push_front(data, sc_new('\013', edit_del_all_right));
		twl_lst_push_front(data, sc_new('\014', edit_clear_screen));
		twl_lst_push_front(data, sc_new('\016', edit_history_down));
		twl_lst_push_front(data, sc_new('\020', edit_history_up));
		twl_lst_push_front(data, sc_new('\021', edit_move_word_left));
		twl_lst_push_front(data, sc_new('\022', edit_research));
		twl_lst_push_front(data, sc_new('\023', edit_move_word_right));
		twl_lst_push_front(data, sc_new('\024', edit_drag_char_before_cursor));
		twl_lst_push_front(data, sc_new('\025', edit_del_all_left));
		twl_lst_push_front(data, sc_new('\027', edit_del_previous_word));
		twl_lst_push_front(data, sc_new('\031', edit_paste));
		twl_lst_push_front(data, sc_new('\177', edit_del_left));
	}
	return (data);
}
