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

#include "twl_get_next_line.h"

t_lst				*history_mgr_new(void)
{
	t_lst			*history;
	char			*filename;
	int				fd;
	char			*line;


	history = twl_lst_new();
	filename = twl_joinpath(getenv("HOME"), HISTORY_FILENAME);
	// twl_lprintf("file: %s\n", filename);
	fd = open(filename, O_RDONLY | O_CREAT, 0644);
	// twl_lprintf("fd: %d\n", fd);
	while (twl_get_next_line(fd, &line))
	{
		// twl_lprintf("line: %s\n", line);
		history_mgr_add(history, line);
		free(line);
	}
	free(filename);
	close(fd);
	return (history);
}
