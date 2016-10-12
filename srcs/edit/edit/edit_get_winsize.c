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
#include <limits.h>

static bool		get_size(t_edit *this, int term)
{
	struct winsize	ws;

	if (ioctl(term, TIOCGWINSZ, &ws) == -1)
	{
		if (errno == EINTR)
		{
			twl_dprintf(2, "ioctl: %s\n", twl_strerror(errno));
			exit(-1);
		}
		return (false);
	}
	this->winsize_x = ws.ws_col;
	return (true);
}

void			edit_get_winsize(t_edit *this)
{
	if (get_size(this, 0) || get_size(this, 1) || get_size(this, 2))
	{
		;
	}
	else
	{
		this->winsize_x = INT_MAX;
	}
}
