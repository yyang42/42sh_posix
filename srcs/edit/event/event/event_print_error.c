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

void			event_print_error(t_event *this, t_event_token *token)
{
	if (this->ret)
		free(this->ret);
	this->ret = NULL;
	if (this->error)
		return ;
	this->error = true;
	if (this->from_history)
		twl_dprintf(2, "42sh: history: %s: history expansion failed\n",
				token->token);
	else
		twl_dprintf(2, "42sh: %s: event not found\n", token->token);
}
