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

t_event_tokenizer		*event_tokenizer_new_from_string(char *string)
{
	t_event_tokenizer	*this;

	this = twl_malloc_x0(sizeof(t_event_tokenizer));
	this->tokens = twl_lst_new();
	this->input = twl_strdup(string);
	this->input_index = 0;
	this->input_length = twl_strlen(this->input);
	this->to_push = twl_strnew(this->input_length);
	this->to_push_index = 0;
	this->quoted = false;
	return (this);
}
