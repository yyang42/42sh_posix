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
#include "twl_ctype.h"

static bool			is_special_parameter(t_brace_tokenizer *this)
{
	char			c;

	c = this->input[this->index_input];
	return (c == '?' ||
			c == '-' ||
			c == '$' ||
			c == '!' ||
			c == '0' ||
			c == '*' ||
			c == '@' ||
			c == '#');
}

static void			brace_push_dollar_parenthesis_tmp(t_brace_tokenizer *this)
{
	if (this->input[this->index_input] == '\\')
		brace_push_escaped(this);
	else if (this->input[this->index_input] == '$')
		brace_push_dollar(this);
	else if (this->input[this->index_input] == '`')
		brace_push_bquote(this);
	else if (this->input[this->index_input] == '"')
		brace_push_dquote(this);
	else if (this->input[this->index_input] == '\'')
		brace_push_squote(this);
	else
		brace_tokenizer_addone(this);
}

static void			brace_push_dollar_parenthesis(t_brace_tokenizer *this)
{
	int				depth;

	brace_tokenizer_addone(this);
	depth = 0;
	while (this->input[this->index_input])
	{
		if (!depth && this->input[this->index_input] == ')')
		{
			brace_tokenizer_addone(this);
			break ;
		}
		if (this->input[this->index_input] == '(')
		{
			brace_tokenizer_addone(this);
			depth += 1;
		}
		else if (this->input[this->index_input] == ')')
		{
			brace_tokenizer_addone(this);
			depth -= 1;
		}
		else
			brace_push_dollar_parenthesis_tmp(this);
	}
}

static void			brace_push_dollar_brace(t_brace_tokenizer *this)
{
	brace_tokenizer_addone(this);
	while (this->input[this->index_input] &&
			this->input[this->index_input] != '}')
	{
		if (this->input[this->index_input] == '\\')
			brace_push_escaped(this);
		else if (this->input[this->index_input] == '$')
			brace_push_dollar(this);
		else if (this->input[this->index_input] == '`')
			brace_push_bquote(this);
		else if (this->input[this->index_input] == '"')
			brace_push_dquote(this);
		else if (this->input[this->index_input] == '\'')
			brace_push_squote(this);
		else
			brace_tokenizer_addone(this);
	}
	if (this->input[this->index_input])
	{
		brace_tokenizer_addone(this);
	}
}

void				brace_push_dollar(t_brace_tokenizer *this)
{
	brace_tokenizer_addone(this);
	if (this->input[this->index_input] == '{')
		brace_push_dollar_brace(this);
	else if (this->input[this->index_input] == '(')
		brace_push_dollar_parenthesis(this);
	else if (is_special_parameter(this))
		brace_tokenizer_addone(this);
	else if (twl_isdigit(this->input[this->index_input]))
		brace_tokenizer_addone(this);
	else if (twl_isalpha(this->input[this->index_input]) ||
			this->input[this->index_input] == '_')
	{
		while (twl_isalnum(this->input[this->index_input]) ||
				this->input[this->index_input] == '_')
			brace_tokenizer_addone(this);
	}
}
