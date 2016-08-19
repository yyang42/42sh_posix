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
# include "edit/event_token.h"
# include "edit/event_tokenizer.h"
# include "twl_ctype.h"
# include "twl_stdlib.h"

typedef struct	s_event
{
	t_edit		*edit;
	t_lst		*tokens;
	char		*ret;
	bool		error;
	bool		expand;
	bool		from_history;
}				t_event;

t_event			*event_new(t_edit *edit);
t_event			*event_new_from_string(char *string);
void			event_del(t_event *this);

char			*event_expand(t_edit *edit);
char			*event_expand_history_string(char *string);

void			event_concat_token(t_event *this, t_event_token *token);
void			event_concat_string(t_event *this, char *str);
void			event_expand_number_line(t_event *this, t_event_token *token);
void			event_expand_number_line_minus(t_event *this,
					t_event_token *token);
void			event_expand_last_command(t_event *this, t_event_token *token);
void			event_expand_command_start(t_event *this, t_event_token *token);
void			event_expand_command_contain(t_event *this,
					t_event_token *token);
void			event_expand_current_line(t_event *this, t_event_token *token);

void			event_print_error(t_event *this, t_event_token *token);

#endif
