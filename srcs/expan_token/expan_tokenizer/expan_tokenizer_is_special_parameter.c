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

bool				expan_tokenizer_is_special_parameter(t_expan_tokenizer *this)
{
	const char		c = this->input[this->input_index];

	return (c == '@' ||
			c == '*' ||
			c == '#' ||
			c == '?' ||
			c == '-' ||
			c == '$' ||
			c == '!' ||
			c == '0');
}
