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

#include "expan/expansion.h"
#include "expan/expan_prompt.h"

int					hex_to_dec(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else
		return (0);
}

void				expansion_prompt_number(t_expansion *this,
											t_expan_token *token)
{
	char			to_push[2];

	if (token->text[1] == 'x' || token->text[1] == 'X')
	{
		*to_push = hex_to_dec(token->text[2]) * 16 + hex_to_dec(token->text[3]);
	}
	else
	{
		*to_push = (token->text[1] - '0') * 64 +
			(token->text[2] - '0') * 8 +
			(token->text[3] - '0');
	}
	to_push[1] = '\0';
	expansion_push_before_split(this, to_push, false);
}
