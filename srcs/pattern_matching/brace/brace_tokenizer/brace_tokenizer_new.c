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

#include "pattern_matching/brace/brace_tokenizer.h"

t_brace_tokenizer		*brace_tokenizer_new(char *input)
{
	t_brace_tokenizer	*this;

	this = twl_malloc_x0(sizeof(t_brace_tokenizer));
	this->tokens = twl_lst_new();
	this->input = twl_strdup(input);
	this->index_input = 0;
	this->to_push = twl_strnew(twl_strlen(input));
	this->index_to_push = 0;
	return (this);
}
