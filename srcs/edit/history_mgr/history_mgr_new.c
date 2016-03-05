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

#include "twl_xsys/stat.h"

#include "edit/history_mgr.h"

#include "shenv/shenv.h"

#include "twl_get_next_line.h"

t_lst				*history_mgr_new(void)
{
	t_lst			*history;
	char			*filename;
	int				fd;
	char			*line;
	char			*home_path;

	home_path = environment_getenv_value(environment_singleton(), "HOME");
	if (!home_path || !twl_isdir(home_path))
		home_path = ".";
	history = twl_lst_new();
	filename = twl_joinpath(home_path, HISTORY_FILENAME);
	fd = open(filename, O_CREAT | O_RDONLY, 0644);
	/*
	** TODO : FD Error handling
	*/
	while (twl_get_next_line(fd, &line))
	{
		history_mgr_add(history, line);
		free(line);
	}
	free(filename);
	close(fd);
	return (history);
}

