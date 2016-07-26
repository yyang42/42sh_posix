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
#include "edit/escaped_sequence.h"

t_lst				*data_escaped_sequence(void)
{
	static t_lst	*data = NULL;

	if (!data)
	{
		data = twl_lst_new();
		twl_lst_push_front(data, escaped_sequence_new("\033b", edit_move_word_left));
		twl_lst_push_front(data, escaped_sequence_new("\033B", edit_move_word_left));
		twl_lst_push_front(data, escaped_sequence_new("\033f", edit_move_word_right));
		twl_lst_push_front(data, escaped_sequence_new("\033F", edit_move_word_right));
		twl_lst_push_front(data, escaped_sequence_new("\033[A", edit_history_up));
		twl_lst_push_front(data, escaped_sequence_new("\033[B", edit_history_down));
		twl_lst_push_front(data, escaped_sequence_new("\033[C", edit_move_right));
		twl_lst_push_front(data, escaped_sequence_new("\033[D", edit_move_left));
		twl_lst_push_front(data, escaped_sequence_new("\033[H", edit_move_home));
		twl_lst_push_front(data, escaped_sequence_new("\033[F", edit_move_end));
		twl_lst_push_front(data, escaped_sequence_new("\033[3~", edit_del_right));
		twl_lst_push_front(data, escaped_sequence_new("\033[5~", edit_move_up));
		twl_lst_push_front(data, escaped_sequence_new("\033[6~", edit_move_down));
	}
	return (data);
}
