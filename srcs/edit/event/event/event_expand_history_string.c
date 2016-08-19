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

static void		iter_expan_fn(void *data, void *ctx)
{
	t_event_token	*token;
	t_event			*this;

	token = data;
	this = ctx;
	if (this->error)
		return ;
	if (token->type == EVENT_NUMBER_LINE)
		event_expand_number_line(this, token);
	else if (token->type == EVENT_NUMBER_LINE_MINUS)
		event_expand_number_line_minus(this, token);
	else if (token->type == EVENT_LAST_COMMAND)
		event_expand_last_command(this, token);
	else if (token->type == EVENT_COMMAND_START)
		event_expand_command_start(this, token);
	else if (token->type == EVENT_COMMAND_CONTAIN)
		event_expand_command_contain(this, token);
	else if (token->type == EVENT_CURRENT_LINE)
		event_expand_current_line(this, token);
	else if (token->type == EVENT_NONE)
		event_concat_token(this, token);
}

char			*event_expand_history_string(char *string)
{
	t_event		*this;
	char		*ret;

	this = event_new_from_string(string);
	this->from_history = true;
	twl_lst_iter(this->tokens, iter_expan_fn, this);
	ret = this->ret;
	this->ret = NULL;
	event_del(this);
	return (ret);
}
