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

#ifndef EVENT_TOKEN_H
# define EVENT_TOKEN_H

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

#endif
