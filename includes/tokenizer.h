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

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "basics.h"

# include "token.h"

typedef enum		e_rule_status
{
	RULE_STATUS_NONE,
	RULE_STATUS_NOT_APPLIED,
	RULE_STATUS_APPLIED,
	RULE_STATUS_END_OF_INPUT
}					t_rule_status;

typedef struct		s_tokenizer
{
	t_lst			*tokens;
	char			*input;
	char			*curpos;
	char			*curtoken;
	char			*curtokenplus;
	bool			cur_is_quoted;
}					t_tokenizer;

t_tokenizer			*tokenizer_new(char *input);
void				tokenizer_del(t_tokenizer *this);

void				tokenizer_delimit(t_tokenizer *this);
void				tokenizer_tokenize(t_tokenizer *this);
void				tokenizer_append_to_curtoken(t_tokenizer *t, int len);

bool				tokenizer_utils_is_start_of_op(t_tokenizer *this, char c);
bool				tokenizer_utils_can_form_operator(t_tokenizer *this,
															char *candidate);
char				*tokenizer_utils_find_closing(char *s, char *open,
																char *close);
char				*tokenizer_utils_find_closing_plus(char *s);


/*
	Tokenizer rules
*/

t_rule_status		tokenizer_apply_rule01(t_tokenizer *this);
t_rule_status		tokenizer_apply_rule02(t_tokenizer *this);
t_rule_status		tokenizer_apply_rule03(t_tokenizer *this);
t_rule_status		tokenizer_apply_rule04(t_tokenizer *this);
t_rule_status		tokenizer_apply_rule05(t_tokenizer *this);
t_rule_status		tokenizer_apply_rule06(t_tokenizer *this);
t_rule_status		tokenizer_apply_rule07(t_tokenizer *this);
t_rule_status		tokenizer_apply_rule08(t_tokenizer *this);
t_rule_status		tokenizer_apply_rule09(t_tokenizer *this);
t_rule_status		tokenizer_apply_rule10(t_tokenizer *this);
t_rule_status		tokenizer_apply_rule11(t_tokenizer *this);

typedef t_rule_status (*t_rule_fn)(t_tokenizer *this);

extern t_rule_fn	tokenizer_rule_fns[12];

#endif
