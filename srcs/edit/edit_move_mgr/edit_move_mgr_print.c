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

static void			print_edit_move_fn(void *edit_move_)
{
	t_edit_move	*edit_move;

	edit_move = edit_move_;
	twl_printf("<Object #%p>\n", edit_move);
}

void				edit_move_mgr_print(t_lst *edit_moves)
{
	twl_printf("%s>>>>>>>>>> edit_move list%s\n", C_CYAN, C_CLEAR);
	twl_lst_iter0(edit_moves, print_edit_move_fn);
	twl_printf("%s-------------------------------------%s\n", C_CYAN, C_CLEAR);
}
