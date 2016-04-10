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

#include "expan/expan_tokenizer.h"

t_expan_tokenizer	*expan_tokenizer_new(char *input)
{
	t_expan_tokenizer	*this;

	this = twl_malloc_x0(sizeof(t_expan_tokenizer));
	this->tokens = twl_lst_new();
	this->input = twl_strdup(input);
	this->length = twl_strlen(input);
	this->to_push = twl_strnew(this->length);
	this->input_index = 0;
	this->to_push_index = 0;
	this->is_last_colon = true;
	return (this);
}
