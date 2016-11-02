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
#include "edit/research.h"
#include "edit/event.h"
#include "utils.h"

void			edit_get_line_init(t_edit *this, t_edit_type type)
{
	this->type = type;
	edit_prompt_print(this);
	utils_tcsetpgrp_for_tty_01(getpid());
	edit_terminal_enable(this);
	edit_new_last_line(this);
	history_get_histsize(this->history);
	if (this->type == edit_type_ps1)
	{
		if (this->last_ps1)
			twl_strdel(&this->last_ps1);
	}
	this->pos_cursor = 0;
}
