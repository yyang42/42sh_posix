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

#include "expan/expan_tilde.h"
#include "twl_get_next_line.h"
#include "twl_arr.h"
#include "twl_stdlib.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pwd.h>

static struct passwd	*getpwinfo(char *line)
{
	char				**split;
	struct passwd		*ret;

	split = twl_strsplit(line, ':');
	if (twl_arr_len(split) != 7)
	{
		twl_arr_del(split, free);
		return (NULL);
	}
	ret = twl_malloc_x0(sizeof(struct passwd));
	ret->pw_name = twl_strdup(split[0]);
	ret->pw_passwd = twl_strdup(split[1]);
	ret->pw_uid = twl_atoi(split[2]);
	ret->pw_gid = twl_atoi(split[3]);
	ret->pw_gecos = twl_strdup(split[4]);
	ret->pw_dir = twl_strdup(split[5]);
	ret->pw_shell = twl_strdup(split[6]);
	twl_arr_del(split, free);
	return (ret);
}

t_lst					*expan_tilde_getpwent(void)
{
	static t_lst		*passwd = NULL;
	struct passwd		*tmppw;
	char				*line;
	int					fd;

	if (passwd == NULL)
	{
		passwd = twl_lst_new();
		if ((fd = open("/etc/passwd", O_RDONLY)) == -1)
			return (passwd);
		while (twl_get_next_line(fd, &line) > 0)
		{
			tmppw = getpwinfo(line);
			if (tmppw != NULL)
				twl_lst_push_front(passwd, tmppw);
			free(line);
		}
		close(fd);
	}
	return (passwd);
}
