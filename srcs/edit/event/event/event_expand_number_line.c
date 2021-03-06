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

void			event_expand_number_line(t_event *this, t_event_token *token)
{
	t_line		*line;
	int			pos;

	this->expand = true;
	pos = twl_atoi(token->token + 1);
	line = history_get_from_number(this->edit->history, pos);
	if (!line)
		event_print_error(this, token);
	else
		event_concat_string(this, line->copy);
}
