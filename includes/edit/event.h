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

typedef struct			s_event
{
	t_edit				*edit;
	t_lst				*tokens;
}						t_event;

t_event					*event_new(t_edit *edit);
void					event_del(t_event *this);

char					*event_expand(t_edit *edit);

#endif
