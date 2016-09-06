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

static void			get_cdpath(t_lst *ret)
{
	char			*cdpath;
	char			**paths;
	size_t			index;

	if (!(cdpath = shenv_shvars_get_value(shenv_singleton(), "CDPATH")))
		return ;
	paths = twl_strsplit(cdpath, ':');
	index = 0;
	while (paths[index])
	{
		if (*paths[index])
			twl_lst_push_back(ret, builtin_cd_new(paths[index], true));
		else
			free(paths[index]);
		index += 1;
	}
	free(paths);
}

static t_lst		*builtin_cd_home(char *dir, t_lst *ret)
{
	char			*tmp;

	tmp = shenv_shvars_get_value(shenv_singleton(), "HOME");
	if (!tmp)
	{
		shenv_singl_error(EXIT_FAILURE, "cd: HOME not set");
		return (ret);
	}
	twl_lst_push_back(ret, builtin_cd_new(twl_strdup(tmp), false));
	return (ret);
	(void)dir;
}

static t_lst		*builtin_cd_oldpwd(char *dir, t_lst *ret)
{
	char			*tmp;

	tmp = shenv_shvars_get_value(shenv_singleton(), "OLDPWD");
	if (!tmp)
	{
		shenv_singl_error(EXIT_FAILURE, "cd: OLDPWD not set");
		return (ret);
	}
	twl_lst_push_back(ret, builtin_cd_new(twl_strdup(tmp), true));
	return (ret);
	(void)dir;
}

t_lst				*builtin_cd_get_directories(char *dir)
{
	t_lst			*ret;

	ret = twl_lst_new();
	if (!dir)
		builtin_cd_home(dir, ret);
	else if (dir[0] == '-' && dir[1] == '\0')
		builtin_cd_oldpwd(dir, ret);
	else if (dir[0] == '/')
		twl_lst_push_back(ret, builtin_cd_new(twl_strdup(dir), false));
	else if (dir[0] == '.' && dir[1] == '/')
		twl_lst_push_back(ret, builtin_cd_new(twl_strdup(dir), false));
	else if (dir[0] == '.' && dir[1] == '.' && dir[2] == '/')
		twl_lst_push_back(ret, builtin_cd_new(twl_strdup(dir), false));
	else
	{
		get_cdpath(ret);
		if (!twl_lst_first(ret))
			twl_lst_push_back(ret, builtin_cd_new(twl_strdup(dir), false));
		else
			twl_lst_push_back(ret, builtin_cd_new(twl_strdup("."), false));
	}
	return (ret);
}
