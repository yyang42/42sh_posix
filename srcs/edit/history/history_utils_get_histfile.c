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

//static bool		is_regular_file(char *path)
//{
//	struct stat	buf;
//
//	if (stat(path, &buf) == -1)
//		return (false);
//	return (S_ISREG(buf.st_mode));
//}
//
//static int		get_fd(char *p)
//{
//	char		*home;
//	char		*path;
//	int			fd;
//	bool		should_free;
//
//	path = p ? p : shenv_shvars_get_value(shenv_singleton(), "HISTFILE");
//	should_free = false;
//	if (!path)
//	{
//		home = shenv_get_home(shenv_singleton());
//		path = twl_joinpath(home, SHENV_DEFAULT_HISTORY_FILE);
//		shenv_shvars_set(shenv_singleton(), "HISTFILE", path, NULL);
//		should_free = true;
//	}
//	if (!is_regular_file(path))
//	{
//		shenv_singl_error(1, "%s: not a regular file", path, strerror(errno));
//		return (-1);
//	}
//	fd = open(path, ) : -1;
//	if (should_free)
//		free(path);
//	if (fd == -1)
//		shenv_singl_error(1, "%s: cannot access: %s", path, strerror(errno));
//	return (fd);
//}

t_lst			*history_utils_get_histfile(char *path)
{
	int			fd;
	char		*str;
	char		*rem;
	t_lst		*lst;

	fd = history_utils_get_fd_histfile(path, O_RDONLY | O_CREAT);
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
