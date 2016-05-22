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

#include "edit/edit.h"
#include "edit/escaped_sequence.h"
#include "data.h"

static bool		find_fn(void *data, void *ctx)
{
	return (twl_strcmp(((t_escaped_sequence *)data)->sequence, ctx) == 0);
}

t_edit_fn		edit_utils_buffer_match_sequence(t_edit *this)
{
	t_escaped_sequence	*esc;

	esc = twl_lst_find(data_escaped_sequence(), find_fn, this->buffer);
	if (esc == NULL)
	{
		return (NULL);
	}
	return (esc->apply_fn);
}
