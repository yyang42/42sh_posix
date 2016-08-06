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

static char		*get_string_fn(char *token)
{
	char		*ret;
	size_t		index;

	ret = twl_strnew(twl_strlen(token));
	index = 0;
	while (*token && *token != '?')
	{
		ret[index] = *token;
		index += 1;
		token += 1;
	}
	ret[index] = 0;
	return (ret);
}

static bool		find_fn(void *data, void *ctx)
{
	char		*haystack;
	char		*needle;

	haystack = ((t_line *)data)->copy;
	needle = ctx;
	return (twl_strstr(haystack, needle));
}

void			event_expand_command_contain(t_event *this,
					t_event_token *token)
{
	t_line		*line;
	char		*tok;

	this->expand = true;
	tok = get_string_fn(token->token + 2);
	if (*tok == 0)
		event_print_error(this, token);
	else
	{
		line = history_find(this->edit->history, find_fn, tok);
		if (!line)
			event_print_error(this, token);
		else
			event_concat_string(this, line->copy);
	}
	free(tok);
}
