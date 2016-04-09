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

#include "expan/expansion_parameter_brace.h"

t_expansion_brace			*expansion_brace_new(char *input)
{
	t_expansion_brace	*this;

	this = twl_malloc_x0(sizeof(t_expansion_brace));
	this->type = BRACE_NOT_APPLIED;
	if (input[2] == '#' && expansion_brace_length_case_applied(this, input))
		return (this);
	expansion_brace_flush_before(this, input);
	if (this->type != BRACE_NOT_APPLIED)
		return (this);
	expansion_brace_flush_token(this, input);
	if (this->type == BRACE_ERROR)
		return (this);
	if ((this->type == BRACE_COLON_EQUAL || this-> type == BRACE_EQUAL) &&
			(twl_isdigit(*this->param) ||
				expan_is_special_parameter(*this->param)))
	{
		expansion_brace_set_error(this, input, "cannot assign in this way");
		return (this);
	}
	this->word = twl_strndup(input + this->index,
										twl_strlen(input) - this->index - 1);
	return (this);
}
