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

#include <fcntl.h>

#include "edit/history_mgr.h"

static void			iter_fn(void *history_line, void *fd_ptr)
{
	int				fd;

	fd = *((int *)fd_ptr);
	if (twl_strlen(history_line) > 0)
	{
		write(fd, history_line, twl_strlen(history_line));
		write(fd, "\n", 1);
	}
}

void				history_mgr_export(t_lst *history)
{
	char			*filename;
	int				fd;


	filename = twl_joinpath(getenv("HOME"), HISTORY_FILENAME);
	fd = open(filename, O_WRONLY | O_CREAT, 0644);
	twl_lst_iter(history, iter_fn, &fd);
	free(filename);
	close(fd);
}
