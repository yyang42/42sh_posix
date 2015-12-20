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

void				tokenizer_tokenize(t_tokenizer *this)
{
	this->i = 0;
	this->ti = 0;
	while (true)
	{
		twl_printf("parser %s\n", &this->input[this->i]);
		if (tokenizer_apply_rule1(this) == END_OF_INPUT)
			break ;
		// (void)(tokenizer_apply_rule2(this)
		// 	&& tokenizer_apply_rule3(this)
		// 	&& tokenizer_apply_rule6(this)
		// 	&& );
		if (tokenizer_apply_rule2(this))
			continue ;
		if (tokenizer_apply_rule3(this))
			continue ;
		if (tokenizer_apply_rule6(this))
			continue ;
		if (tokenizer_apply_rule8(this))
			continue ;
		this->ti++;
		this->i++;
	}
}
