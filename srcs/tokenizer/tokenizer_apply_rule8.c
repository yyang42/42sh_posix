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

/*  Rule 8
	If the current character is an unquoted <blank>, any token
	containing the previous character is delimited and the current
	character shall be discarded.
*/

int					tokenizer_apply_rule8(t_tokenizer *this)
{
	char			*input;

	input = this->input;
	if (*this->curpos == ' ')
	{
		tokenizer_delimit(this);
		this->curpos++;
		return (1);
	}
	return (0);
}
