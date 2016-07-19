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

#include "edit/research.h"

void			research_clear_prompt(t_edit *this)
{
	char		*tmp;

	if (this->base_x < this->prompt_size)
	{
		tputs(tgoto(tgetstr("UP", NULL), 0,
					this->prompt_size / this->winsize_x), 1, this->putc);
	}
	this->putc('\r');
	tmp = twl_strnewc(this->prompt_size, ' ');
	this->puts(tmp);
	if (this->base_x == 0)
		this->puts("\n\r");
	free(tmp);
	if (this->base_x < this->prompt_size)
	{
		tputs(tgoto(tgetstr("UP", NULL), 0,
					this->prompt_size / this->winsize_x), 1, this->putc);
	}
	this->putc('\r');
}
