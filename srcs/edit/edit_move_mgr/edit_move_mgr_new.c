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

#include "edit/edit_move_mgr.h"
#include "edit/edit.h"


t_lst				*edit_move_mgr_new(void)
{
	t_lst			*edit_moves;

	edit_moves = twl_lst_new();
	edit_move_mgr_add(edit_moves, edit_move_new(ARROW_LEFT, edit_move_left));
	edit_move_mgr_add(edit_moves, edit_move_new(ARROW_RIGHT, edit_move_right));
	edit_move_mgr_add(edit_moves, edit_move_new(CTRL_A, edit_move_start));
	edit_move_mgr_add(edit_moves, edit_move_new(CTRL_E, edit_move_end));
	return (edit_moves);
}
