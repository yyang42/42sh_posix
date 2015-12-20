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

#include <stdlib.h>

#include "tokenizer.h"

/*  Rule 8
	If the current character is an unquoted <blank>, any token
	containing the previous character is delimited and the current
	character shall be discarded.
*/

void				tokenizer_apply_rule8(t_tokenizer *this)
{
	char			*input;

	input = this->input;
	if (input[this->i] == ' ')
	{
		tokenizer_delimit(this);
	}
	else
	{
		this->ti++;
	}
}
