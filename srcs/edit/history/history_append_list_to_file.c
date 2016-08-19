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
#include <fcntl.h>

static void		get_hist_to_append(t_history *this, t_lst *histfile)
{
	t_histlist	*tmp;

	tmp = this->last;
	twl_lst_rev(histfile);
	while (tmp && tmp->limit == false && tmp->prev && tmp->prev->limit == false)
		tmp = tmp->prev;
	if (tmp && tmp->limit == true && !tmp->next)
	{
		twl_lst_rev(histfile);
		return ;
	}
	if (tmp)
		tmp->limit = false;
	if (tmp && tmp->prev)
		tmp->prev->limit = false;
	if (this->last)
		this->last->limit = true;
	while (tmp)
	{
		twl_lst_push_front(histfile, twl_strdup(tmp->line->copy));
		tmp = tmp->next;
	}
	twl_lst_rev(histfile);
}

static void		iter_fn(void *data, void *ctx)
{
	twl_dprintf(*(int *)ctx, "%s\n", data);
}

void			history_append_list_to_file(t_history *this, char *path)
{
	t_lst		*histfile;
	size_t		histfilesize;
	size_t		newhistfilesize;
	int			fd;

	if (!(histfile = history_utils_get_histfile(path)))
		return ;
	get_hist_to_append(this, histfile);
	histfilesize = history_get_histfilesize(this);
	newhistfilesize = twl_lst_len(histfile);
	while (newhistfilesize > histfilesize)
	{
		free(twl_lst_pop_front(histfile));
		newhistfilesize -= 1;
	}
	fd = history_utils_get_fd_histfile(path, O_WRONLY | O_TRUNC | O_CREAT);
	if (fd == -1)
	{
		twl_lst_del(histfile, free);
		return ;
	}
	twl_lst_iter(histfile, iter_fn, &fd);
	twl_lst_del(this->save, free);
	this->save = histfile;
}
