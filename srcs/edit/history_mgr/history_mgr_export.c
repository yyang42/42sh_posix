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
#include "shenv/shenv.h"

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

	filename = shenv_get_home(shenv_singleton());
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	twl_lst_iter(history, iter_fn, &fd);
	close(fd);
}
