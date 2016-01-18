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
#include "edit/edit.h"


t_lst				*edit_key_mgr_new(void)
{
	t_lst			*edit_keys;

	edit_keys = twl_lst_new();
	edit_key_mgr_add(edit_keys, edit_key_new(ARROW_LEFT, edit_move_left));
	edit_key_mgr_add(edit_keys, edit_key_new(ARROW_RIGHT, edit_move_right));
	edit_key_mgr_add(edit_keys, edit_key_new(CTRL_A, edit_move_start));
	edit_key_mgr_add(edit_keys, edit_key_new(CTRL_E, edit_move_end));
	edit_key_mgr_add(edit_keys, edit_key_new(DELETE_KEY, edit_delete_letter));
	edit_key_mgr_add(edit_keys, edit_key_new(CTRL_C, edit_handle_ctrl_c));
	edit_key_mgr_add(edit_keys, edit_key_new(CTRL_D, edit_handle_ctrl_d));
	edit_key_mgr_add(edit_keys, edit_key_new(RETURN_KEY, edit_key_return));
	edit_key_mgr_add(edit_keys, edit_key_new(CTRL_T, edit_move_prev_word));
	edit_key_mgr_add(edit_keys, edit_key_new(CTRL_U, edit_move_next_word));
	edit_key_mgr_add(edit_keys, edit_key_new(CTRL_W, edit_delete_prev_word));
	edit_key_mgr_add(edit_keys, edit_key_new(ARROW_UP, edit_history_up));
	edit_key_mgr_add(edit_keys, edit_key_new(ARROW_DOWN, edit_history_down));
	edit_key_mgr_add(edit_keys, edit_key_new(CTRL_I, edit_start_stop_cpy));
	edit_key_mgr_add(edit_keys, edit_key_new(CTRL_P, edit_paste_clip));
	return (edit_keys);
}
