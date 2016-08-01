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

/*
** (...) except when followed by a blank, newline, carriage return, = or (
*/

static bool			is_valid_fn(char c)
{
	return (c && !twl_isblank(c)  && c != '=' && c != '(');
}

//static bool			is_number_except_zero(char *str)
//{
//	int				i;
//
//	if (twl_isdigit(*str) || *str == '-')
//	{
//		i = twl_atoi(str);
//		return (i != 0);
//	}
//	return (false);
//}

t_rule_event_status	event_tokenizer_apply_rule03(t_event_tokenizer *this)
{
	if (this->input[this->input_index] == '!' &&
			is_valid_fn(this->input[this->input_index + 1]))
	{
		event_tokenizer_delimit(this, EVENT_NONE);
	//	event_tokenizer_addone(this);
	//	if (this->input[this->input_index] == '!' ||
	//			this->input[this->input_index] == '#')
	}
	return (EVENT_STATUS_NOT_APPLIED);
}
