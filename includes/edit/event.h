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

#ifndef EVENT_H
# define EVENT_H

# include "utils.h"
# include "edit/edit.h"
# include "twl_ctype.h"
# include "twl_stdlib.h"

typedef enum			e_event_token_type
{
	EVENT_NUMBER_LINE,
	EVENT_NUMBER_LINE_MINUS,
	EVENT_LAST_COMMAND,
	EVENT_COMMAND_START,
	EVENT_COMMAND_CONTAIN,
	EVENT_CURRENT_LINE,
	EVENT_NONE
}						t_event_token_type;

typedef struct			s_event_token
{
	char				*token;
	t_event_token_type	type;
}						t_event_token;

t_event_token			*event_token_new(char *input, t_event_token_type type);
void					event_token_del(t_event_token *this);

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
void					event_tokenizer_del(t_event_tokenizer *this);

t_lst					*event_tokenizer_tokenize(t_edit *edit);
t_rule_event_status		event_tokenizer_apply_rule01(t_event_tokenizer *this);
t_rule_event_status		event_tokenizer_apply_rule02(t_event_tokenizer *this);
t_rule_event_status		event_tokenizer_apply_rule03(t_event_tokenizer *this);
t_rule_event_status		event_tokenizer_apply_rule04(t_event_tokenizer *this);

void					event_tokenizer_delimit(t_event_tokenizer *this, t_event_token_type type);
void					event_tokenizer_addone(t_event_tokenizer *this);
void					event_tokenizer_number_line(t_event_tokenizer *this);
void					event_tokenizer_number_line_minus(t_event_tokenizer *this);
void					event_tokenizer_last_command(t_event_tokenizer *this);
void					event_tokenizer_command_start(t_event_tokenizer *this);
void					event_tokenizer_command_contain(t_event_tokenizer *this);
void					event_tokenizer_current_line(t_event_tokenizer *this);

typedef t_rule_event_status	(*t_event_tokenizer_fn)(t_event_tokenizer *);

typedef struct			s_event
{
	t_edit				*edit;
	t_lst				*tokens;
}						t_event;

t_event					*event_new(t_edit *edit);
void					event_del(t_event *this);

char					*event_expand(t_edit *edit);

#endif
