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

static void			init_fn(t_edit *this)
{
	utils_tcsetpgrp_for_tty_01(getpid());
	edit_prompt_print(this);
	edit_terminal_enable(this);
	edit_new_last_line(this);
	if (this->type == edit_type_ps1)
	{
		if (this->last_ps1)
			twl_strdel(&this->last_ps1);
	}
	this->pos_cursor = 0;
}

size_t		upper_power_of_two(size_t v)
{
	v -= 1;
	v |= v >> 1;
	v |= v >> 2;
	v |= v >> 4;
	v |= v >> 8;
	v |= v >> 16;
	v += 1;
	return (v);
}


static bool			is_end_fn(t_edit *this)
{
	char			*expand;
	char			*tmp;
	size_t			len;
	size_t			tot;

	expand = event_expand(this);
	if (!expand)
	{
		this->research_mode = false;
		research_del(this->research);
		this->research = NULL;
		line_del(this->last);
		this->last = line_new();
		this->current = this->last;
		this->index_history = 0;
		this->pos_cursor = 0;
		this->type = edit_type_ps1;
		edit_prompt_print(this);
		return (false);
	}
	len = twl_strlen(expand);
	if (len % 2 == 0)
	{
		tot = len << 1;
	}
	else
	{
		tot = upper_power_of_two(len);
	}
	tmp = twl_strnew(tot);
	twl_strcpy(tmp, expand);
	free(this->current->line);
	this->current->line = tmp;
	this->current->size = len;
	this->current->total = tot;
	return (true);
}

static char			*end_fn(t_edit *this)
{
	char			*ret;

	edit_terminal_disable(this);
	if (this->type == edit_type_ps1)
	{
		ret = twl_strdup(this->current->line);
	}
	else
	{
		ret = twl_strjoin(this->last_ps1, this->current->line);
	}
	this->last_ps1 = twl_strjoin(ret, "\n");
	edit_history_push_flush(this);
	return (ret);
}

static char			*end_exit_fn(t_edit *this)
{
	research_end(this);
	edit_terminal_disable(this);
	this->puts("\n\r");
	return (twl_strdup("exit\n"));
}

static bool			is_ignoreeof_set(t_edit *this)
{
	research_end(this);
	if (!shenv_shflag_enabled(shenv_singleton(), "ignoreeof"))
		return (false);
	this->puts("Use \"exit\" to leave the shell.");
	this->puts("\n\r");
	edit_prompt_print(this);
	return (true);
}

char				*edit_get_line(t_edit *this, t_edit_type type)
{
	unsigned char	buf;
	int				read_return;

	this->type = type;
	init_fn(this);
	while (1)
	{
		if ((read_return = read(0, &buf, sizeof(buf))) == -1)
		{
		    if (errno == EINTR)
		    {
		    	LOG_ERROR("read: System interrupt received: ignore and continue");
		    	continue ;
		    }
		    LOG_ERROR("read: %s\n", strerror(errno));
			twl_dprintf(2, "read: %s\n", strerror(errno));
			edit_terminal_disable(this);
			exit(-1);
		}
		if (this->is_last_tab)
			this->is_last_tab -= 1;
		if (read_return == 0 && !*this->current->line)
			return (end_exit_fn(this));
		if (((buf == '\x0d' || buf == '\n') && !*this->buffer) ||
				read_return == 0)
		{
			this->puts("\n\r");
			if (is_end_fn(this))
				break ;
			continue ;
		}
		if (buf == '\x04' && !*this->current->line && !is_ignoreeof_set(this))
			return (end_exit_fn(this));
		edit_match_char(this, buf);
	}
	return (end_fn(this));
}
