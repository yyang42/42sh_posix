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

#include "twl_gnl.h"

t_lst				*history_mgr_new(void)
{
	t_lst			*history;
	char			*filename;
	int				fd;
	char			*line;
	char			*home_path;
	char			*gnl_remainder;

	home_path = shenv_shvars_get_value(shenv_singleton(), "HOME");
	if (!home_path || !twl_isdir(home_path))
		home_path = ".";
	history = twl_lst_new();
	filename = twl_joinpath(home_path, HISTORY_FILENAME);
	fd = open(filename, O_CREAT | O_RDONLY, 0644);
	/*
	** TODO : FD Error handling
	*/
	gnl_remainder = NULL;
	while (twl_gnl(fd, &line, &gnl_remainder) > 0)
	{
		history_mgr_add(history, line);
		free(line);
	}
	free(filename);
	free(gnl_remainder);
	close(fd);
	return (history);
}

