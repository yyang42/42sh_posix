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

static void		init_term(t_edit *this)
{
	if (tcgetattr(0, &this->term))
	{
		if (errno == EINTR)
		{
			twl_dprintf(2, "tcgetattr: %s\n", strerror(errno));
			exit(-1);
		}
		this->echoing = true;
	}
	if (tcgetattr(0, &this->save))
	{
		if (errno == EINTR)
		{
			twl_dprintf(2, "tcgetattr: %s\n", strerror(errno));
			exit(-1);
		}
		this->echoing = true;
	}
}

void			edit_terminal_init(t_edit *this)
{
	char		*term;

	term = shenv_shvars_get_value(shenv_singleton(), "TERM");
	this->dumb = false;
	if (tgetent(NULL, term) == -1)
	{
		if (tgetent(NULL, "dumb") == -1)
		{
			twl_dprintf(2, "tgetent: %s\n", strerror(errno));
			exit(-1);
		}
		this->dumb = true;
	}
	init_term(this);
	if (this->echoing)
		return ;
	this->term.c_lflag &= ~(ICANON | ECHO | IEXTEN);
	this->term.c_oflag &= ~(ONLCR | OPOST);
	this->term.c_cc[VMIN] = 1;
	this->term.c_cc[VTIME] = 0;
}
