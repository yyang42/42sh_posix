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

void			edit_terminal_init(t_edit *this)
{
	char		*term;

	term = shenv_shvars_get_value(shenv_singleton(), "TERM");
	if (tgetent(NULL, term) == -1)
	{
		if (tgetent(NULL, "dumb") == -1)
		{
			twl_dprintf(2, "tgetent: %s\n", strerror(errno));
			exit(-1);
		}
	}
	if (tcgetattr(0, &this->term))
	{
		twl_dprintf(2, "tcgetattr: %s\n", strerror(errno));
		exit(-1);
	}
	if (tcgetattr(0, &this->save))
	{
		twl_dprintf(2, "tcgetattr: %s\n", strerror(errno));
		exit(-1);
	}
	this->term.c_lflag &= ~(ICANON | ECHO | ISIG);
	this->term.c_oflag &= ~(ONLCR | OPOST);
	this->term.c_cc[VMIN] = 1;
	this->term.c_cc[VTIME] = 0;
	this->term.c_cc[VDSUSP] = 0;
	this->term.c_cc[VLNEXT] = 0;
}
