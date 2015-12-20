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

#include "twl_xstdlib.h"

#include "tokenizer.h"

static void			tokenizer_tokenize(t_lst *tokens, char *input)
{
	int				gi;
	int				curi;

	gi = 0;
	curi = 0;
	while (true)
	{
		/*  Rule 8
			If the end of input is recognized, the current token shall
			be delimited. If there is no current token, the end-of-input
			indicator shall be returned as the token.
		*/
		if (input[gi] == '\0')
		{
			twl_lst_push(tokens, twl_strndup(&(input[gi - curi]), curi));
			break ;
		}

		/*  Rule 8
			If the current character is an unquoted <blank>, any token
			containing the previous character is delimited and the current
			character shall be discarded.
		*/
		if (input[gi] == ' ')
		{
			twl_lst_push(tokens, twl_strndup(&(input[gi - curi]), curi));
			curi = 0;
		}
		else
		{
			curi++;
		}
		gi++;
	}
}

t_tokenizer			*tokenizer_new(char *input)
{
	t_tokenizer		*this;

	this = twl_malloc_x0(sizeof(t_tokenizer));
	this->tokens = twl_lst_new();
	tokenizer_tokenize(this->tokens, input);
	return (this);
}
