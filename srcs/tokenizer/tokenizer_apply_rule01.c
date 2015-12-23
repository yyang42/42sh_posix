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

/*  Rule 1
	If the end of input is recognized, the current token shall
	be delimited. If there is no current token, the end-of-input
	indicator shall be returned as the token.

	end-of-input => -1
*/

int					tokenizer_apply_rule01(t_tokenizer *this)
{
	if (*this->curpos == '\0')
	{
		COUCOU;
		if (*this->curtoken)
		{
			tokenizer_delimit(this);
		}
		return (END_OF_INPUT);
	}
	return (-1);
}
