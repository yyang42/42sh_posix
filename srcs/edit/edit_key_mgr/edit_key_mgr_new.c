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
	return (edit_keys);
}
