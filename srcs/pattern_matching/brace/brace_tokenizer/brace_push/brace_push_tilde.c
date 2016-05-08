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

void				brace_push_tilde(t_brace_tokenizer *this)
{
	while (this->input[this->index_input] &&
			this->input[this->index_input] != ':' &&
			this->input[this->index_input] != '/')
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
}
