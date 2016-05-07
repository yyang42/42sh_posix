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
# include "pattern_matching/brace/brace_token.h"
# include "pattern_matching/brace/brace_utils.h"

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
	size_t				total;
	t_lst				*brace;
}						t_brace_tokenizer;

t_brace_tokenizer		*brace_tokenizer_new(char *input);
void					brace_tokenizer_del(t_brace_tokenizer *this);

t_brace_tokenizer		*brace_tokenizer_copy_current(t_brace_tokenizer *this);

t_lst					*brace_tokenizer_tokenize(char *input);

void					brace_tokenizer_addone(t_brace_tokenizer *this);
t_rule_brace_status		brace_tokenizer_apply_rule01(t_brace_tokenizer *this);
t_rule_brace_status		brace_tokenizer_apply_rule02(t_brace_tokenizer *this);
t_rule_brace_status		brace_tokenizer_apply_rule03(t_brace_tokenizer *this);
t_rule_brace_status		brace_tokenizer_apply_rule04(t_brace_tokenizer *this);
t_rule_brace_status		brace_tokenizer_apply_rule05(t_brace_tokenizer *this);
t_rule_brace_status		brace_tokenizer_apply_rule06(t_brace_tokenizer *this);
t_rule_brace_status		brace_tokenizer_apply_rule07(t_brace_tokenizer *this);
void					brace_tokenizer_delimit(t_brace_tokenizer *this,
							t_brace_token_type type);

typedef t_rule_brace_status	(*t_brace_tokenizer_fn)(t_brace_tokenizer *this);

void					brace_push_bquote(t_brace_tokenizer *this);
void					brace_push_dollar(t_brace_tokenizer *this);
void					brace_push_dquote(t_brace_tokenizer *this);
void					brace_push_escaped(t_brace_tokenizer *this);
void					brace_push_squote(t_brace_tokenizer *this);
void					brace_push_tilde(t_brace_tokenizer *this);

void					brace_push_sequence(t_brace_tokenizer *this);
void					brace_push_brace(t_brace_tokenizer *this);
t_brace_token_type		brace_could_push_brace(t_brace_tokenizer *this);
void					brace_test_push_brace(t_brace_tokenizer *this);

bool					brace_tokenizer_is_sequence_digit(
							t_brace_tokenizer *this);
bool					brace_tokenizer_is_sequence_alpha(
							t_brace_tokenizer *this);

#endif
