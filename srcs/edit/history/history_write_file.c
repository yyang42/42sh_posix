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

static t_histlist	*get_histlist_first(t_history *this, size_t histfilesize)
{
	t_histlist		*tmp;

	if (histfilesize > this->length)
		return (this->first);
	tmp = this->last;
	while (tmp && tmp->prev && histfilesize)
	{
		histfilesize -= 1;
		tmp = tmp->prev;
	}
	return (tmp);

}

void			history_write_file(t_history *this, char *path)
{
	int			fd;
	size_t		histfilesize;
	t_histlist	*tmp;

	fd = history_utils_get_fd_histfile(path, O_WRONLY | O_TRUNC | O_CREAT);
	if (fd == -1)
		return ;
	histfilesize = history_get_histfilesize(this);
	tmp = get_histlist_first(this, histfilesize);
	while (tmp)
	{
		twl_dprintf(fd, "%s\n", tmp->line->copy);
		tmp = tmp->next;
	}
	close(fd);
}
