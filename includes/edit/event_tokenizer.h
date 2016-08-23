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

#ifndef EVENT_TOKENIZER_H
# define EVENT_TOKENIZER_H

# include "utils.h"
# include "edit/edit.h"
# include "edit/event.h"
# include "edit/event_token.h"
# include "twl_ctype.h"
# include "twl_stdlib.h"

typedef enum			e_rule_event_status
{
	EVENT_STATUS_APPLIED,
	EVENT_STATUS_NOT_APPLIED,
	EVENT_STATUS_END_OF_INPUT
}						t_rule_event_status;

typedef	struct			s_event_tokenizer
{
	t_lst				*tokens;
	char				*input;
	size_t				input_index;
	char				*to_push;
	size_t				to_push_index;
	size_t				input_length;
	bool				quoted;
}						t_event_tokenizer;

t_event_tokenizer		*event_tokenizer_new(t_edit *edit);
t_event_tokenizer		*event_tokenizer_new_from_string(char *string);
void					event_tokenizer_del(t_event_tokenizer *this);

t_lst					*event_tokenizer_tokenize(t_edit *edit);
t_lst					*event_tokenizer_tokenize_from_string(char *string);
t_rule_event_status		event_tokenizer_apply_rule01(t_event_tokenizer *this);
t_rule_event_status		event_tokenizer_apply_rule02(t_event_tokenizer *this);
t_rule_event_status		event_tokenizer_apply_rule03(t_event_tokenizer *this);
t_rule_event_status		event_tokenizer_apply_rule04(t_event_tokenizer *this);

void					event_tokenizer_delimit(t_event_tokenizer *this,
							t_event_token_type type);
void					event_tokenizer_addone(t_event_tokenizer *this);
void					event_tokenizer_number_line(t_event_tokenizer *this);
void					event_tokenizer_number_line_minus(
		t_event_tokenizer *this);
void					event_tokenizer_last_command(t_event_tokenizer *this);
void					event_tokenizer_command_start(t_event_tokenizer *this);
void					event_tokenizer_command_contain(
		t_event_tokenizer *this);
void					event_tokenizer_current_line(t_event_tokenizer *this);

typedef t_rule_event_status	(*t_event_tokenizer_fn)(t_event_tokenizer *);

#endif
