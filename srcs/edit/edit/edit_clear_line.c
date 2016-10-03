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

void			edit_clear_line(t_edit *this)
{
	edit_move_end(this);
	this->research_mode = false;
	research_del(this->research);
	this->research = NULL;
	line_del(this->last);
	this->last = line_new();
	this->current = this->last;
	history_reset_current(this->history);
	this->pos_cursor = 0;
	this->puts("\n\r");
	if (this->last_ps1)
		free(this->last_ps1);
	this->last_ps1 = NULL;
	this->type = edit_type_ps1;
	edit_prompt_print(this);
}
