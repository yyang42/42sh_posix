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

#include "builtin/cmds/builtin_cd.h"

char			*builtin_cd_make_path_from_dir(char *path, char *dir)
{
	char		*ret;
	char		*tret;

	if (CD_ROOTEDPATH(dir))
		return (twl_strdup(dir));
	if (!path)
		return (NULL);
	ret = twl_strnew(twl_strlen(dir) + twl_strlen(path) + 2);
	tret = ret;
	while (*path)
	{
		*tret = *path;
		tret += 1;
		path += 1;
	}
	*tret = CD_DIRSEP;
	twl_strcpy(tret + 1, dir);
	return (ret);
}
