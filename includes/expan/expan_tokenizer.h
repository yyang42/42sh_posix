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

#ifndef EXPAN_TOKENIZER_H
# define EXPAN_TOKENIZER_H

# include "basics.h"
# include "ast/ast.h"
# include "expan/expan_token.h"

typedef enum		e_rule_expan_status
{
	EXPAN_STATUS_APPLIED,
	EXPAN_STATUS_NOT_APPLIED,
	EXPAN_STATUS_END_OF_INPUT
}					t_rule_expan_status;

typedef struct		s_expan_tokenizer
{
	t_lst			*tokens;
	char			*input;
	size_t			input_index;
	char			*to_push;
	size_t			to_push_index;
	size_t			length;
	bool			is_last_colon;
}					t_expan_tokenizer;

t_expan_tokenizer	*expan_tokenizer_new(char *input);
void				expan_tokenizer_del(t_expan_tokenizer *this);

t_lst				*expan_tokenizer_tokenize(char *input);
t_lst				*expan_tokenizer_tokenize_remove_squote(
														char *input);
t_lst				*expan_tokenizer_tokenize_prompt(char *input);

t_rule_expan_status	expan_tokenizer_apply_rule01(t_expan_tokenizer *this);
t_rule_expan_status	expan_tokenizer_apply_rule02(t_expan_tokenizer *this);
t_rule_expan_status	expan_tokenizer_apply_rule03(t_expan_tokenizer *this);
t_rule_expan_status	expan_tokenizer_apply_rule04(t_expan_tokenizer *this);
t_rule_expan_status	expan_tokenizer_apply_rule05(t_expan_tokenizer *this);
t_rule_expan_status	expan_tokenizer_apply_rule06(t_expan_tokenizer *this);
t_rule_expan_status	expan_tokenizer_apply_rule07(t_expan_tokenizer *this);
t_rule_expan_status	expan_tokenizer_apply_rule_prompt(t_expan_tokenizer *this);

void				expan_tokenizer_delimit(t_expan_tokenizer *this,
		t_expan_token_type type);
void				expan_tokenizer_addone(t_expan_tokenizer *this);

bool				expan_tokenizer_is_special_parameter(
		t_expan_tokenizer *this);

/*
** Push functions:
*/

void				expan_push_bquote(t_expan_tokenizer *this);
void				expan_push_dollar(t_expan_tokenizer *this);
void				expan_push_dquote(t_expan_tokenizer *this);
void				expan_push_escaped(t_expan_tokenizer *this);
void				expan_push_squote(t_expan_tokenizer *this);
void				expan_push_tilde(t_expan_tokenizer *this);

typedef t_rule_expan_status	(*t_expan_tokenizer_fn)(t_expan_tokenizer *this);

#endif
