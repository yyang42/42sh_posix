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
#include "edit/simple_char.h"
#include "data.h"

static bool		find_fn(void *data, void *ctx)
{
	return (((t_simple_char *)data)->simple == *((unsigned char *)ctx));
}

t_edit_fn		edit_utils_buf_match_simple(t_edit *this, unsigned char buf)
{
	t_simple_char	*esc;

	esc = twl_lst_find(data_simple_char_edit(), find_fn, &buf);
	if (esc == NULL)
	{
		return (NULL);
	}
	return (esc->apply_fn);
	(void)this;
}
