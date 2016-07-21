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

static void			init_fn(t_edit *this, t_edit_type type)
{
	utils_tcsetpgrp_for_tty_01(getpid());
	edit_prompt_print(this, type);
	edit_terminal_enable(this);
	edit_new_last_line(this);
	if (type == edit_type_ps1)
	{
		if (this->last_ps1)
			twl_strdel(&this->last_ps1);
	}
	this->pos_cursor = 0;
}

static char			*end_fn(t_edit *this, t_edit_type type)
{
	char			*ret;

	edit_terminal_disable(this);
	this->putc('\n');
	if (type == edit_type_ps1 || !this->last_ps1)
	{
		ret = twl_strdup(this->current->line);
		this->last_ps1 = twl_strjoin(ret, "\n");
	}
	else
	{
		ret = twl_strjoin(this->last_ps1, this->current->line);
		this->last_ps1 = twl_strjoin(ret, "\n");
	}
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
	edit_prompt_print(this, this->last_ps1 ? edit_type_ps2 : edit_type_ps1);
	return (true);
}

char				*edit_get_line(t_edit *this, t_edit_type type)
{
	unsigned char	buf;
	int				read_return;

	init_fn(this, type);
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
			exit(-1);
		}
		if (this->is_last_tab)
			this->is_last_tab -= 1;
		if (read_return == 0 && !*this->current->line)
			return (end_exit_fn(this));
		if (read_return == 0)
			break ;
		if ((buf == '\x0d' || buf == '\n') && !*this->buffer)
		{
			research_end(this);
			edit_move_end(this);
			break ;
		}
		if (buf == '\x04' && !*this->current->line && !is_ignoreeof_set(this))
			return (end_exit_fn(this));
		edit_match_char(this, buf);
	}
	return (end_fn(this, type));
}
