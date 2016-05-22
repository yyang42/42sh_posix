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
	return (twl_strncmp(((t_escaped_sequence *)data)->sequence,
				ctx, twl_strlen(ctx)) == 0);
}

bool			edit_utils_can_buffer_form_sequence(t_edit *this)
{
	return (twl_lst_find(data_escaped_sequence(), find_fn, this->buffer) != 0);
}
