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

#include "pattern_matching/brace/brace_token.h"

t_brace_token		*brace_token_new(char *input, bool to_expand)
{
	t_brace_token	*this;

	this = twl_malloc_x0(sizeof(t_brace_token));
	this->input = twl_strdup(input);
	this->to_expand = to_expand;
	return (this);
}
