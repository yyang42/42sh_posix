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

#include "token/tokenizer.h"

t_rule_status		tokenizer_arexp_apply_rule01(t_tokenizer *this)
{
	if (*this->curpos == '\0')
	{
		if (*this->curtoken)
		{
			tokenizer_arexp_delimit(this);
		}
		return (RULE_STATUS_END_OF_INPUT);
	}
	return (RULE_STATUS_NOT_APPLIED);
}
