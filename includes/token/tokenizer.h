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

# include "token/token.h"

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
	int				cur_line;
	int				cur_col;
	char			*heredoc_pos;
	char			*err_msg;
	t_lst			*tok_open_stack;
	t_lst			*open_heredoc_tokens;
}					t_tokenizer;

t_lst				*tokenizer_tokenize(t_tokenizer *this);
t_lst				*tokenizer_utils_tokenize(char *input);

t_tokenizer			*tokenizer_new(char *input);
void				tokenizer_del(t_tokenizer *this);

void				tokenizer_append_to_curtoken(t_tokenizer *t, int len);

bool				tokenizer_utils_is_start_of_op(t_tokenizer *this, char c);
bool				tokenizer_utils_can_form_operator(t_tokenizer *this,
															char *candidate);

void				tokenizer_delimit(t_tokenizer *this);
void				tokenizer_delimit_handle_heredoc(t_tokenizer *this,
														t_token *new_token);
void				tokenizer_remove_line_continuation(t_tokenizer *t);
void				tokenizer_utils_remove_line_continuation(char *str);
void				tokenizer_record_heredoc(t_tokenizer *t,
		t_token *new_token);

void				tokenizer_build_heredoc(t_tokenizer *t, t_token *new_token,
	char *pos, bool skip_leading_tabs);
char				*tokenizer_get_delimiter(char *str);
bool				tokenizer_is_delimiter(char *pos, char *delimiter);

/*
**	Tokenizer rules
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

/*
**	Tokenizer Arithmetic Expansion
*/

t_lst				*tokenizer_arexp_tokenize(char *input);
bool				tokenizer_arexp_utils_is_start_of_op(t_tokenizer *this,
		char c);
bool				tokenizer_arexp_utils_can_form_operator(t_tokenizer *this,
		char *candidate);
void				tokenizer_arexp_delimit(t_tokenizer *this);
t_rule_status		tokenizer_arexp_apply_rule01(t_tokenizer *this);
t_rule_status		tokenizer_arexp_apply_rule02(t_tokenizer *this);
t_rule_status		tokenizer_arexp_apply_rule03(t_tokenizer *this);
t_rule_status		tokenizer_arexp_apply_rule04(t_tokenizer *this);
t_rule_status		tokenizer_arexp_apply_rule05(t_tokenizer *this);
t_rule_status		tokenizer_arexp_apply_rule06(t_tokenizer *this);

typedef t_rule_status	(*t_rule_fn)(t_tokenizer *this);

#endif
