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

#include "token/tokenizer.h"
#include "token/token_mgr.h"
#include "utils.h"
#include "twl_ctype.h"

static void			set_prev_to_io_number_if_necessary(t_tokenizer *this,
													t_token *token)
{
	t_token			*prev;

	if (str_is_redir_operator(token->text))
	{
		prev = token_mgr_last(this->tokens);
		if (prev && twl_str_is_pos_num(prev->text))
		{
			if (twl_isdigit(*(this->curpos - twl_strlen(token->text) - 1)))
			{
				prev->type = TOKEN_IO_NUMBER;
			}
		}
	}
}

static void			update_line_and_col(t_tokenizer *t)
{
	t->cur_line += twl_str_count_char(t->curtoken, '\n');
	if (twl_str_count_char(t->curtoken, '\n'))
		t->cur_col = twl_strlen(twl_strrchr(t->curtoken, '\n'));
	else
		t->cur_col += twl_strlen(t->curtoken);
}

static t_token		*create_token(t_tokenizer *t)
{
	t_token			*token;

	token = token_new(t->curtoken, t->cur_line, t->cur_col);
	update_line_and_col(t);
	set_prev_to_io_number_if_necessary(t, token);
	tokenizer_delimit_handle_heredoc(t, token);
	return (token);
}

void				tokenizer_delimit(t_tokenizer *this)
{
	if (*this->curtoken != '\0')
	{
		twl_lst_push(this->tokens, create_token(this));
		this->curtoken[0] = '\0';
	}
}
