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

#include "edit/history.h"
#include "twl_gnl.h"
#include <sys/stat.h>
#include <fcntl.h>

static bool		is_regular_file(char *path)
{
	struct stat	buf;

	if (stat(path, &buf) == -1)
		return (false);
	return (S_ISREG(buf.st_mode));
}

static int		get_fd(void)
{
	char		*home;
	char		*path;
	int			fd;
	bool		should_free;

	path = shenv_shvars_get_value(shenv_singleton(), "HISTFILE");
	should_free = false;
	if (!path)
	{
		home = shenv_get_home(shenv_singleton());
		path = twl_joinpath(home, SHENV_DEFAULT_HISTORY_FILE);
		shenv_shvars_set(shenv_singleton(), "HISTFILE", path, NULL);
		should_free = true;
	}
	fd = (is_regular_file(path) ? open(path, O_RDONLY) : -1);
	if (should_free)
		free(path);
	return (fd);
}

static void			history_inner_pop(t_history *this)
{
	t_histlist		*tmp;

	if (!this->first)
		return ;
	if (this->first == this->last)
	{
		line_del(this->first->line);
		free(this->first);
		this->last = NULL;
		this->first = NULL;
	}
	else
	{
		tmp = this->first->next;
		tmp->prev = NULL;
		line_del(this->first->line);
		free(this->first);
		this->first = tmp;
	}
	this->current = this->last;
	this->length -= 1;
}

static void			history_inner_push(t_history *this, t_line *line)
{
	t_histlist		*lst;

	lst = twl_malloc_x0(sizeof(t_histlist));
	lst->line = line;
	lst->limit = false;
	if (this->last)
	{
		lst->number = this->last->number + 1;
		lst->prev = this->last;
		this->last->next = lst;
	}
	else
	{
		lst->number = 1;
		this->first = lst;
	}
	this->last = lst;
	this->length += 1;
	this->current = this->last;
	while (this->length > this->total)
		history_inner_pop(this);
}

void			history_read_file(t_history *this)
{
	int			fd;
	int			gnl_ret;
	char		*str;
	char		*rem;

	fd = get_fd();
	if (fd == -1)
		return ;
	str = NULL;
	rem = NULL;
	while ((gnl_ret = twl_gnl(fd, &str, &rem)) > 0)
	{
		LOG_DEBUG("%i: %s", gnl_ret, str);
		if (!*str)
		{
			free(str);
			continue ;
		}
		history_inner_push(this, line_new_from_string(str));
		free(str);
	}
	free(rem);
	history_reset_numbers(this);
	close(fd);
}
