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

static void		iter_fn(void *data)
{
	t_event_token	*token;

	token = data;
	LOG_DEBUG("%s >%s<", event_token_type_to_string(token->type), token->token);
}

char			*event_expand(t_edit *edit)
{
	t_event		*this;

	this = event_new(edit);
	twl_lst_iter0(this->tokens, iter_fn);
	event_del(this);
	return (NULL);
}
