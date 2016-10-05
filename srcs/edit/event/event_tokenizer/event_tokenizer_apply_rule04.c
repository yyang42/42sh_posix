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

t_rule_event_status	event_tokenizer_apply_rule04(t_event_tokenizer *this)
{
	if (this->input[this->input_index] == '\\' &&
			this->input[this->input_index + 1])
	{
		event_tokenizer_addone(this);
	}
	else if (this->input[this->input_index] == '\'')
	{
		this->quoted = true;
	}
	event_tokenizer_addone(this);
	return (EVENT_STATUS_APPLIED);
}
