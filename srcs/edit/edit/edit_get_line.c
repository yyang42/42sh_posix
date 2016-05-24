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

static char			*end_exit_fn(t_edit *this)
{
	edit_terminal_disable(this);
	this->putc('\n');
	return (twl_strdup("exit\n"));
}

char				*edit_get_line(t_edit *this)
{
	unsigned char	buf;
	int				read_return;

	init_fn(this);
	while (1)
	{
		if ((read_return = read(0, &buf, sizeof(buf))) == -1)
		{
			twl_dprintf(2, "read: %s\n", strerror(errno));
			exit(-1);
		}
		if (read_return == 0 && !*this->current->line)
			return (end_exit_fn(this));
		if (read_return == 0)
			break ;
		if (buf == '\n' && !*this->buffer)
			break ;
		if (buf == '\x04' && !*this->current->line)
			return (end_exit_fn(this));
		edit_match_char(this, buf);
	}
	return (end_fn(this));
}