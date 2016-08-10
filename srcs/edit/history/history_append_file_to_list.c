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

static int		get_fd(char *p)
{
	char		*home;
	char		*path;
	int			fd;
	bool		should_free;

	path = p ? p : shenv_shvars_get_value(shenv_singleton(), "HISTFILE");
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
	if (fd == -1)
		shenv_singl_error(1, "%s: cannot access: %s", path, strerror(errno));
	return (fd);
}

static t_lst	*get_lst(char *path)
{
	int			fd;
	char		*str;
	char		*rem;
	t_lst		*lst;

	fd = get_fd(path);
	if (fd == -1)
		return (NULL);
	str = NULL;
	rem = NULL;
	lst = twl_lst_new();
	while (twl_gnl(fd, &str, &rem))
	{
		if (!*str)
		{
			free(str);
			continue ;
		}
		twl_lst_push_front(lst, str);
	}
	free(rem);
	close(fd);
	twl_lst_rev(lst);
	return (lst);
}

static void		iter_fn(void *data, void *ctx1, void *ctx2)
{
	char		*ctx_first;
	t_history	*this;

	ctx_first = twl_lst_pop_front(ctx1);
	this = ctx2;
	if (!this->is_break && !ctx_first)
	{
		history_push(ctx2, line_new_from_string(data));
	}
	else if (!this->is_break && !twl_strcmp(ctx_first, data))
	{
		;
	}
	else
	{
		this->is_break = true;
	}
}

static void		find_and_slice(t_history *this, t_lst *content)
{
	t_lst		*copy;
	t_lst		*copy_copy;
	char		*copy_first;
	char		*content_first;

	copy = twl_lst_copy(this->save, NULL);
	content_first = twl_lst_first(content);
	while ((copy_first = twl_lst_first(copy)))
	{
		if (twl_strcmp(copy_first, content_first))
		{
			twl_lst_pop_front(copy);
			continue ;
		}
		this->is_break = false;
		copy_copy = twl_lst_copy(copy, NULL);
		twl_lst_iter2(content, iter_fn, copy_copy, this);
		if (!twl_lst_first(copy_copy))
			break ;
		twl_lst_pop_front(copy);
	}
}

void			history_append_file_to_list(t_history *this, char *path)
{
	t_lst		*content;

	if (!(content = get_lst(path)))
		return ;
	find_and_slice(this, content);
	twl_lst_del(this->save, free);
	this->save = content;
}
