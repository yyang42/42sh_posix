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
#include "edit/edit_key_func.h"
#include "edit/terminal.h"

void				edit_handle_ctrl_c(void *_edit)
{
	t_edit			*edit;

	edit = _edit;
	edit->return_cmd = true;
	edit_print_letters(edit);
	edit_clear_line(edit);
	edit->state = NORMAL;
	edit->return_cmd = false;
}
