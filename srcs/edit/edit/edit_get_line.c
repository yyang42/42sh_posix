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
#include "edit/research.h"
#include "edit/event.h"
#include "utils.h"

static char			*end_fn(t_edit *this)
{
	char			*ret;

	edit_terminal_disable(this);
	if (this->type == edit_type_ps1)
	{
		ret = twl_strdup(this->current->line);
		if (this->last_ps1)
			free(this->last_ps1);
	}
	else
	{
		ret = twl_strjoinfree(this->last_ps1, this->current->line, 'l');
	}
	this->last_ps1 = twl_strjoin(ret, "\n");
	edit_history_push_flush(this);
	return (ret);
}

static char			*end_exit_fn(t_edit *this)
{
	char			*ret;

	research_end(this);
	edit_terminal_disable(this);
	this->puts("\n\r");
	if (this->last_ps1)
	{
		ret = this->last_ps1;
		this->last_ps1 = NULL;
		this->shall_exec = true;
		return (ret);
	}
	return (twl_strdup("exit\n"));
}

static bool			init_loop(t_edit *this,
		unsigned char *buf, int *read_return)
{
	*buf = 0;
	if ((*read_return = read(0, buf, sizeof(*buf))) == -1)
	{
		if (errno == EINTR)
		{
			LOG_ERROR("read: System interrupt received: ignore and continue");
			return (false);
		}
		LOG_ERROR("read: %s\n", twl_strerror(errno));
		twl_dprintf(2, "read: %s\n", twl_strerror(errno));
		edit_terminal_disable(this);
		shenv_utils_exit(-1);
	}
	if (this->is_last_tab)
		this->is_last_tab -= 1;
	return (true);
}

char				*edit_get_line(t_edit *this, t_edit_type type)
{
	unsigned char	buf;
	int				read_return;

	edit_get_line_init(this, type);
	while (1)
	{
		if (!init_loop(this, &buf, &read_return))
			continue ;
		if (read_return == 0 && !*this->current->line)
			return (end_exit_fn(this));
		if (((buf == '\x0d' || buf == '\n') && !*this->buffer) ||
				read_return == 0)
		{
			research_end(this);
			this->puts("\r\n");
			if (edit_get_line_is_end(this))
				break ;
			continue ;
		}
		if (buf == '\x04' && !*this->current->line && edit_is_eof_set(this))
			return (end_exit_fn(this));
		edit_match_char(this, buf);
	}
	return (end_fn(this));
}
