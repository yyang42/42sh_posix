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

# define END_OF_INPUT 1

typedef struct		s_tokenizer
{
	t_lst			*tokens;
	char			*input;
	char			*curpos;
	char			*curtoken;
	char			*curtokenplus;
	t_tokentype		tokentype;
}					t_tokenizer;

t_tokenizer			*tokenizer_new(char *input);
void				tokenizer_del(t_tokenizer *this);

void				tokenizer_delimit(t_tokenizer *this);
void				tokenizer_tokenize(t_tokenizer *this);
void				tokenizer_append_to_curtoken(t_tokenizer *t);

int					tokenizer_apply_rule01(t_tokenizer *this);
int					tokenizer_apply_rule02(t_tokenizer *this);
int					tokenizer_apply_rule03(t_tokenizer *this);
int					tokenizer_apply_rule06(t_tokenizer *this);
int					tokenizer_apply_rule07(t_tokenizer *this);
int					tokenizer_apply_rule08(t_tokenizer *this);
int					tokenizer_apply_rule011(t_tokenizer *this);

bool				tokenizer_utils_is_start_of_op(t_tokenizer *this, char c);
bool				tokenizer_utils_can_form_operator(t_tokenizer *this,
															char *candidate);

#endif
