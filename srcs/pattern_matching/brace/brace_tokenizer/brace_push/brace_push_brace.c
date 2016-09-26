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

static void		push_brace(t_brace_tokenizer *this)
{
	twl_lst_push_back(this->brace, twl_strdup(this->to_push));
	twl_bzero(this->to_push, twl_strlen(this->to_push));
	this->index_input += 1;
	this->index_to_push = 0;
}

static bool		try_push01(t_brace_tokenizer *this, char c, size_t *depth)
{
	bool		ret;

	ret = false;
	if (c == '$' && (ret = true))
		brace_push_dollar(this);
	else if (c == '`' && (ret = true))
		brace_push_bquote(this);
	else if (c == '\'' && (ret = true))
		brace_push_squote(this);
	else if (c == '"' && (ret = true))
		brace_push_dquote(this);
	else if (c == '\\' && (ret = true))
		brace_push_escaped(this);
	else if (this->input[this->index_input] == '{' && (ret = true))
	{
		*depth += 1;
		brace_tokenizer_addone(this);
	}
	return (ret);
}

void			brace_push_brace(t_brace_tokenizer *this)
{
	size_t		depth;
	
	depth = 0;
	this->index_input += 1;
	this->total = 0;
	while (!(this->input[this->index_input] == 0 ||
				(depth == 0 && this->input[this->index_input] == '}')))
	{
		if (try_push01(this, this->input[this->index_input], &depth))
			;
		else if (this->input[this->index_input] == '}')
		{
			depth -= 1;
			brace_tokenizer_addone(this);
		}
		else if (this->input[this->index_input] == ',' && depth == 0)
			push_brace(this);
		else
			brace_tokenizer_addone(this);
	}
	push_brace(this);
}
