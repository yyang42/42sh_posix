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

static void		brace_test_push_brace_end_loop_fn(t_brace_tokenizer *this,
		size_t *depth)
{
	if (this->input[this->index_input] == '{')
	{
		*depth += 1;
		this->index_input += 1;
	}
	else if (this->input[this->index_input] == '}')
	{
		*depth -= 1;
		this->index_input += 1;
	}
	else if (this->input[this->index_input] == ',' && *depth == 0)
	{
		this->total += 1;
		this->index_input += 1;
	}
	else
		brace_tokenizer_addone(this);
}

void			brace_test_push_brace(t_brace_tokenizer *this)
{
	size_t		depth;

	depth = 0;
	this->index_input += 1;
	this->total = 0;
	while (true)
	{
		if (this->input[this->index_input] == 0 ||
				(depth == 0 && this->input[this->index_input] == '}'))
			break ;
		if (this->input[this->index_input] == '$')
			brace_push_dollar(this);
		else if (this->input[this->index_input] == '`')
			brace_push_bquote(this);
		else if (this->input[this->index_input] == '\'')
			brace_push_squote(this);
		else if (this->input[this->index_input] == '"')
			brace_push_dquote(this);
		else if (this->input[this->index_input] == '\\')
			brace_push_escaped(this);
		else
			brace_test_push_brace_end_loop_fn(this, &depth);
	}
}
