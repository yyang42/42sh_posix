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

#include "pattern_matching/brace/brace_tokenizer.h"

void				brace_tokenizer_delimit(t_brace_tokenizer *this,
												bool expand)
{
	t_brace_token	*brace_token;

	brace_token = brace_token_new(this->to_push, expand);
	twl_bzero(this->to_push, this->length);
	this->to_push_index = 0;
	twl_lst_push_back(this->tokens, brace_token);
}
