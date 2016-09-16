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
		if (str == NULL)
		{
			continue ;
		}
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
