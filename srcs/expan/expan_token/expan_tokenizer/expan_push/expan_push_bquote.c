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

void				expan_push_bquote(t_expan_tokenizer *this)
{
	expan_tokenizer_addone(this);
	while (this->input[this->input_index] &&
			this->input[this->input_index] != '`')
	{
		if (this->input[this->input_index] == '\\' &&
				(this->input[this->input_index + 1] == '`' ||
					this->input[this->input_index + 1] == '$' ||
					this->input[this->input_index + 1] == '\\'))
			expan_tokenizer_addone(this);
		expan_tokenizer_addone(this);
	}
	if (this->input[this->input_index])
		expan_tokenizer_addone(this);
}
