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

t_rule_event_status	event_tokenizer_apply_rule01(t_event_tokenizer *this)
{
	if (this->input[this->input_index] == '\0')
	{
		event_tokenizer_delimit(this, EVENT_NONE);
		return (EVENT_STATUS_END_OF_INPUT);
	}
	return (EVENT_STATUS_NOT_APPLIED);
}
