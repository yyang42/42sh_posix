/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.h                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 41:59:59 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRACE_TOKENIZER_H
# define BRACE_TOKENIZER_H

# include "basics.h"

typedef enum			e_rule_brace_status
{
	BRACE_STATUS_APPLIED,
	BRACE_STATUS_NOT_APPLIED,
	BRACE_STATUS_END_OF_INPUT
}						t_rule_brace_status;

typedef struct			s_brace_tokenizer
{
	t_lst				*tokens;
	char				*input;
	size_t				index_input;
	char				*to_push;
	size_t				index_to_push;
}						t_brace_tokenizer;

t_brace_tokenizer		*brace_tokenizer_new(char *input);
void					*brace_tokenizer_del(t_brace_tokenizer *this);

t_lst					*brace_tokenizer_expand(char *input);

typedef t_rule_brace_status	(*t_brace_tokenizer_fn)(t_expan_tokenizer *this);

#endif
