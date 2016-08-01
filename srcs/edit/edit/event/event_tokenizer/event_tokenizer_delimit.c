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

void				event_tokenizer_delimit(t_event_tokenizer *this,
						t_event_token_type type)
{
	t_event_token	*token;

	if (!*this->to_push)
		return ;
	token = event_token_new(this->to_push, type);
	twl_lst_push_back(this->tokens, token);
	twl_bzero(this->to_push, this->input_length);
	this->to_push_index = 0;
}
