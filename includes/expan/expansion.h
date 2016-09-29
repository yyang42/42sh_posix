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

#ifndef EXPANSION_H
# define EXPANSION_H

# include "basics.h"
# include "token/token.h"
# include "expan/expan_tokenizer.h"
# include "expan/expan_before_split.h"
# include "expan/expan_utils.h"
# include "twl_ctype.h"
# include "edit/prompt_info.h"

typedef struct		s_expansion
{
	t_lst			*tokens;
	t_lst			*before_split;
	t_lst			*to_push_bs;
	t_lst			*after_split;
	char			*to_push_as;
	char			*ifs;
	t_lst			*patmatch;
	char			*error;
	bool			quoted;
	bool			is_at_present;
	bool			flag_prompt;
	bool			flag_prompt_open_close;
	size_t			size_prompt;
}					t_expansion;

t_expansion			*expansion_new(void);
void				expansion_del(t_expansion *this);

t_expansion			*expansion_new_from_text(char *text);
t_expansion			*expansion_new_from_text_remove_squote(char *text);
t_expansion			*expansion_new_from_text_prompt(char *text);
t_expansion			*expansion_new_from_token(t_token *to_expand);

t_lst				*expansion_get_fields_simple_command(t_expansion *this);
t_lst				*expansion_get_fields_arexp(t_expansion *this);
t_lst				*expansion_get_fields_dquote(t_expansion *this);
t_lst				*expansion_get_fields_word(t_expansion *this);
t_lst				*expansion_get_fields_redir(t_expansion *this);
t_lst				*expansion_get_fields_for_clause(t_expansion *this);

char				*expansion_get_string_needle_case(t_expansion *this);
char				*expansion_get_string_pattern_case(t_expansion *this);
char				*expansion_get_string_assign(t_expansion *this);
char				*expansion_get_string_heredoc(t_expansion *this);
t_prompt_info		expansion_get_prompt_info(t_expansion *this);

void				expansion_tilde(t_expansion *this,
											t_expan_token *token);
void				expansion_no_tilde(t_expansion *this,
											t_expan_token *token);
void				expansion_tilde_split(t_expansion *this,
											t_expan_token *token);
void				expansion_no_tilde_split(t_expansion *this,
											t_expan_token *token);
void				expansion_parameter(t_expansion *this,
											t_expan_token *token);
void				expansion_parameter_special(t_expansion *this,
											t_expan_token *token);
void				expansion_cmdsbt_dollar(t_expansion *this,
											t_expan_token *token);
void				expansion_cmdsbt_bquote(t_expansion *this,
											t_expan_token *token);
char				*expansion_cmdsbt_bquote_getstring(char *text);
void				expansion_arithmetic(t_expansion *this,
											t_expan_token *token);
void				expansion_dquote_wrap(t_expansion *this,
											t_expan_token *token);
void				expansion_dquote_unwrap(t_expansion *this,
											t_expan_token *token);
void				expansion_prompt(t_expansion *this, t_expan_token *token);
void				expansion_prompt_number(t_expansion *this,
											t_expan_token *token);

void				expansion_push_before_split(t_expansion *this,
												char *text, bool split);
void				expansion_push_before_split_s(t_expansion *this,
													char *text, bool split);
void				expansion_push_raw_lst(t_expansion *this, t_lst *lst);
void				expansion_push_quoted_lst(t_expansion *this, t_lst *lst);

void				expansion_push_lst_before_split(t_expansion *this,
		t_lst *lst);

void				expansion_parameter_brace(t_expansion *expansion,
												t_expan_token *token);

void				expansion_field_splitting(t_expansion *this);
void				expansion_splitting(t_expansion *this, char *text);
void				expansion_splitting_push(t_expansion *this,
		char *text, size_t *index);
void				expansion_splitting_split(t_expansion *this, size_t *index);

void				expansion_patmatch(t_expansion *this);

#endif
