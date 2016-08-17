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

t_event			*event_new(t_edit *edit)
{
	t_event		*this;

	this = twl_malloc_x0(sizeof(t_event));
	this->edit = edit;
	this->tokens = event_tokenizer_tokenize(edit);
	this->ret = twl_strnew(0);
	this->error = false;
	this->expand = false;
	this->from_history = false;
	return (this);
}
