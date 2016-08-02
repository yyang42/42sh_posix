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

#include "edit/event_tokenizer.h"

void				event_tokenizer_command_contain(t_event_tokenizer *this)
{
	event_tokenizer_addone(this);
	while (this->input[this->input_index] &&
			this->input[this->input_index] != '?' &&
			!twl_isblank(this->input[this->input_index]))
		event_tokenizer_addone(this);
	if (twl_isblank(this->input[this->input_index]))
		event_tokenizer_delimit(this, EVENT_COMMAND_START);
	else
		event_tokenizer_delimit(this, EVENT_COMMAND_CONTAIN);
}
