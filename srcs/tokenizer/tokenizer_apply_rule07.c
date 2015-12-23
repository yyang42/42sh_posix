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

/*  Rule 7
	If the current character is an unquoted <newline>,
	the current token shall be delimited.
*/

int					tokenizer_apply_rule07(t_tokenizer *t)
{
	if (*t->curpos == '\n')
	{
		COUCOU;
		tokenizer_delimit(t);
		t->curpos++;
		return (1);
	}
	return (0);
}
