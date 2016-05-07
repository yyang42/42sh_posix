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

#include "pattern_matching/brace/brace.h"

t_lst			*brace_expand(char *input)
{
	t_brace		*this;
	t_lst		*ret;

	this = brace_new();
	this->begin = brace_tokenizer_tokenize(input);
	brace_recurs(this, this->begin->head, twl_strnew(0));
	twl_lst_rev(this->final);
	ret = this->final;
	this->final = NULL;
	return (ret);
}
