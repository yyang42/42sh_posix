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

/*
** Check for brace.
*/

static void				push_sequence_digit(t_brace_tokenizer *this)
{
	brace_push_sequence(this);
	this->brace = brace_expand_sequence_digit(this->to_push);
	twl_bzero(this->to_push, twl_strlen(this->to_push));
	brace_tokenizer_delimit(this, BRACE_SEQUENCE_DIGIT);
}

static void				push_sequence_alpha(t_brace_tokenizer *this)
{
	brace_push_sequence(this);
	this->brace = brace_expand_sequence_alpha(this->to_push);
	twl_bzero(this->to_push, twl_strlen(this->to_push));
	brace_tokenizer_delimit(this, BRACE_SEQUENCE_ALPHA);
}

static void				push_list(t_brace_tokenizer *this)
{
	this->brace = twl_lst_new();
	brace_push_brace(this);
	brace_tokenizer_delimit(this, BRACE_LIST);
	this->brace = NULL;
}

t_rule_brace_status		brace_tokenizer_apply_rule02(t_brace_tokenizer *this)
{
	t_brace_token_type	type;

	if (this->input[this->index_input] == '{')
	{
		if ((type = brace_could_push_brace(this)) == BRACE_IGNORE)
			return (BRACE_STATUS_NOT_APPLIED);
		if (this->index_to_push > 0)
			brace_tokenizer_delimit(this, BRACE_IGNORE);
		if (type == BRACE_SEQUENCE_DIGIT)
			push_sequence_digit(this);
		else if (type == BRACE_SEQUENCE_ALPHA)
			push_sequence_alpha(this);
		else
			push_list(this);
		return (BRACE_STATUS_APPLIED);
	}
	return (BRACE_STATUS_NOT_APPLIED);
}
