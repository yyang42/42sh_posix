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

void				expan_tokenizer_delimit(t_expan_tokenizer *this,
														t_expan_token_type type)
{
	t_expan_token	*expan_token;

	expan_token = expan_token_new(type, twl_strdup(this->to_push));
	twl_bzero(this->to_push, this->length);
	this->to_push_index = 0;
	twl_lst_push_back(this->tokens, expan_token);
}
