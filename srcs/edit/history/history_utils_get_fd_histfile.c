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

static void		history_utils_get_fd_histfile_init(char *p,
		char **path, bool *should_free)
{
	int			fd;

	*path = p ? p : shenv_shvars_get_value(shenv_singleton(), "HISTFILE");
	fd = open(*path, O_RDWR | O_CREAT, 0644);
	if (fd >= 0)
		close(fd);
	*should_free = false;
}

int				history_utils_get_fd_histfile(char *p, int opt)
{
	char		*home;
	char		*path;
	int			fd;
	bool		should_free;

	history_utils_get_fd_histfile_init(p, &path, &should_free);
	if (!path)
	{
		home = shenv_get_home(shenv_singleton());
		path = twl_joinpath(home, SHENV_DEFAULT_HISTORY_FILE);
		shenv_shvars_set(shenv_singleton(), "HISTFILE", path, NULL);
		should_free = true;
	}
	if (!is_regular_file(path))
	{
		shenv_singl_error(1, "%s: not a regular file", path, strerror(errno));
		return (-1);
	}
	fd = open(path, opt);
	if (should_free)
		free(path);
	if (fd == -1)
		shenv_singl_error(1, "%s: cannot access: %s", path, strerror(errno));
	return (fd);
}
