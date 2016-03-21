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

#include "expan/expan_tokenizer.h"

void				expan_push_dquote(t_expan_tokenizer *this)
{
	while (this->input[this->input_index] &&
			this->input[this->input_index] == '"')
	{
		if (this->input[this->input_index] == '$')
			expan_push_dollar(this);
		else if (this->input[this->input_index] == '`')
			expan_push_bquote(this);
		else
			expan_tokenizer_addone(this);
	}
}
