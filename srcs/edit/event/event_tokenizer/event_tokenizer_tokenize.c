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

t_event_tokenizer_fn	g_event_tokenizer_rule_fns[5] =
{
	event_tokenizer_apply_rule01,
	event_tokenizer_apply_rule02,
	event_tokenizer_apply_rule03,
	event_tokenizer_apply_rule04,
	NULL
};

t_lst					*event_tokenizer_tokenize(t_edit *edit)
{
	t_event_tokenizer	*this;
	t_rule_event_status	status;
	size_t				index;
	t_lst				*ret;

	this = event_tokenizer_new(edit);
	index = 0;
	while (g_event_tokenizer_rule_fns[index])
	{
		status = g_event_tokenizer_rule_fns[index](this);
		if (status == EVENT_STATUS_END_OF_INPUT)
			break ;
		index = status == EVENT_STATUS_APPLIED ? 0 : index + 1;
	}
	ret = this->tokens;
	this->tokens = NULL;
	event_tokenizer_del(this);
	return (ret);
}
