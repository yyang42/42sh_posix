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

#include "edit/event.h"

void			event_expand_last_command(t_event *this, t_event_token *token)
{
	this->expand = true;
	if (this->edit->size_history == 0)
	{
		event_print_error(this, token);
		return ;
	}
	event_concat_string(this,
			((t_line *)twl_lst_first(this->edit->history))->copy);
}
