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

#include "edit/event_token.h"

const char			*event_token_type_to_string(t_event_token_type type)
{
	if (type == EVENT_NUMBER_LINE)
		return ("Number line");
	if (type == EVENT_NUMBER_LINE_MINUS)
		return ("Number line minus");
	if (type == EVENT_LAST_COMMAND)
		return ("Last command");
	if (type == EVENT_COMMAND_START)
		return ("Command start with");
	if (type == EVENT_COMMAND_CONTAIN)
		return ("Command contain");
	if (type == EVENT_CURRENT_LINE)
		return ("Current line");
	return ("None");
}
