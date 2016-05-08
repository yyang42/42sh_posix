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
#include "twl_ctype.h"

static void			expan_push_dollar_parenthesis_tmp(t_expan_tokenizer *this)
{
	if (this->input[this->input_index] == '\\')
		expan_push_escaped(this);
	else if (this->input[this->input_index] == '$')
		expan_push_dollar(this);
	else if (this->input[this->input_index] == '`')
		expan_push_bquote(this);
	else if (this->input[this->input_index] == '"')
		expan_push_dquote(this);
	else if (this->input[this->input_index] == '\'')
		expan_push_squote(this);
	else
		expan_tokenizer_addone(this);
}

static void			expan_push_dollar_parenthesis(t_expan_tokenizer *this)
{
	int				depth;

	expan_tokenizer_addone(this);
	depth = 0;
	while (this->input[this->input_index])
	{
		if (!depth && this->input[this->input_index] == ')')
		{
			expan_tokenizer_addone(this);
			break ;
		}
		if (this->input[this->input_index] == '(')
		{
			expan_tokenizer_addone(this);
			depth += 1;
		}
		else if (this->input[this->input_index] == ')')
		{
			expan_tokenizer_addone(this);
			depth -= 1;
		}
		else
			expan_push_dollar_parenthesis_tmp(this);
	}
}

static void			expan_push_dollar_brace(t_expan_tokenizer *this)
{
	expan_tokenizer_addone(this);
	while (this->input[this->input_index] &&
			this->input[this->input_index] != '}')
	{
		if (this->input[this->input_index] == '\\')
			expan_push_escaped(this);
		else if (this->input[this->input_index] == '$')
			expan_push_dollar(this);
		else if (this->input[this->input_index] == '`')
			expan_push_bquote(this);
		else if (this->input[this->input_index] == '"')
			expan_push_dquote(this);
		else if (this->input[this->input_index] == '\'')
			expan_push_squote(this);
		else
			expan_tokenizer_addone(this);
	}
	if (this->input[this->input_index])
		expan_tokenizer_addone(this);
}

void				expan_push_dollar(t_expan_tokenizer *this)
{
	expan_tokenizer_addone(this);
	if (this->input[this->input_index] == '{')
		expan_push_dollar_brace(this);
	else if (this->input[this->input_index] == '(')
		expan_push_dollar_parenthesis(this);
	else if (expan_tokenizer_is_special_parameter(this))
		expan_tokenizer_addone(this);
	else if (twl_isdigit(this->input[this->input_index]))
		expan_tokenizer_addone(this);
	else if (twl_isalpha(this->input[this->input_index]) ||
			this->input[this->input_index] == '_')
	{
		while (twl_isalnum(this->input[this->input_index]) ||
				this->input[this->input_index] == '_')
			expan_tokenizer_addone(this);
	}
}
