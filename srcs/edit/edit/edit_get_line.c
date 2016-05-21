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

void				edit_print_prompt(t_edit *this)
{
	this->puts(PS1);
	this->base_x = twl_strlen(PS1) % this->winsize_x;
}

static void			init_fn(t_edit *this)
{
	edit_terminal_enable(this);
	edit_print_prompt(this);
	edit_new_last_line(this);
	this->pos_cursor = 0;
}

static char			*end_fn(t_edit *this)
{
	edit_terminal_disable(this);
	this->putc('\n');
	return (twl_strdup(this->current->line));
}

char				*edit_get_line(t_edit *this)
{
	unsigned char	buf;

	init_fn(this);
	while (1)
	{
		if (read(0, &buf, sizeof(buf)) == -1)
			break ;
		if (!*this->buffer && buf == '\n')
			break ;
		edit_match_char(this, buf);
	}
	return (end_fn(this));
}
