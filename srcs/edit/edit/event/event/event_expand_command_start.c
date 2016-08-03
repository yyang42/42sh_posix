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

static bool		find_fn(void *data, void *ctx1, void *ctx2)
{
	t_line		*line;
	size_t		*len;

	line = data;
	len = ctx2;
	return (twl_strncmp(line->copy, ctx1, *len) == 0);
}

void			event_expand_command_start(t_event *this, t_event_token *token)
{
	t_line		*line;
	size_t		len;

	this->expand = true;
	len = twl_strlen(token->token + 1);
	line = twl_lst_find2(this->edit->history, find_fn, token->token + 1, &len);
	if (!line)
		event_print_error(this, token);
	else
		event_concat_string(this, line->copy);
}
