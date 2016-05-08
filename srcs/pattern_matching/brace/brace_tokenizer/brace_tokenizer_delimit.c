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
						t_brace_token_type type)
{
	t_brace_token	*brace_token;

	if (type == BRACE_IGNORE)
		brace_token = brace_token_new(type, this->to_push);
	else
		brace_token = brace_token_new(type, this->brace);
	twl_bzero(this->to_push, this->index_to_push);
	this->index_to_push = 0;
	twl_lst_push_back(this->tokens, brace_token);
	this->brace = NULL;
}
