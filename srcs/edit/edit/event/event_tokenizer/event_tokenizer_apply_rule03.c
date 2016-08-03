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

/*
** (...) except when followed by a blank, newline, carriage return, = or (
*/

static bool			is_valid_fn(char c)
{
	return (c && !twl_isblank(c)  && c != '=' && c != '(');
}

t_rule_event_status	event_tokenizer_apply_rule03(t_event_tokenizer *this)
{
	if (this->input[this->input_index] == '!' &&
			is_valid_fn(this->input[this->input_index + 1]))
	{
		event_tokenizer_delimit(this, EVENT_NONE);
		event_tokenizer_addone(this);
		if (this->input[this->input_index] == '!')
			event_tokenizer_last_command(this);
		else if (this->input[this->input_index] == '#')
			event_tokenizer_current_line(this);
		else if (twl_isdigit(this->input[this->input_index]))
			event_tokenizer_number_line(this);
		else if (this->input[this->input_index] == '-' &&
				twl_isdigit(this->input[this->input_index + 1]))
			event_tokenizer_number_line_minus(this);
		else if (this->input[this->input_index] == '?')
			event_tokenizer_command_contain(this);
		else
			event_tokenizer_command_start(this);
		return (EVENT_STATUS_APPLIED);
	}
	return (EVENT_STATUS_NOT_APPLIED);
}
