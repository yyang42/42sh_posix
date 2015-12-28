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


#include "tokenizer.h"

static t_token		*create_token(t_tokenizer *this)
{
	t_token			*token;

	token = token_new(twl_strdup(this->curtoken));
	return (token);
}

void				tokenizer_delimit(t_tokenizer *this)
{
	if (*this->curtoken != '\0')
	{
		twl_lst_push(this->tokens, create_token(this));
		this->curtoken[0] = '\0';
	}
}
