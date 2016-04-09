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

static void	set_oldpwd(t_shenv *env)
{
	char			*oldpwd;

	oldpwd = shenv_shvars_get_value(env, "PWD");
	if (oldpwd != NULL)
	{
		shenv_shvars_set(env, "OLDPWD", oldpwd, "cd");
	}
}

static void	set_pwd(char *pwd, t_shenv *env)
{
	shenv_shvars_set(env, "PWD", pwd, "cd");
}

static void	cd_symlink(char *path, t_shenv *this)
{
	char buf[PATH_MAX];

	if (chdir(path) == 0)
	{
		set_oldpwd(this);
		getcwd(buf, PATH_MAX);
		set_pwd(buf, this);
	}
}

void				builtin_cd_exec_do(char *path, char *original_path, int follow_symlinks, t_shenv *this)
{
	char			*new_path;

	new_path = NULL;
	if (follow_symlinks)
		new_path = set_canonical_form(path);
	if (!follow_symlinks)
	{
		cd_symlink(path, this);
	}
	else
	{
		if (chdir(new_path) == -1)
		{
			shenv_singl_error(EXIT_FAILURE, "cd: %s: %s", original_path, strerror(errno));
		}
		else
		{
			set_oldpwd(this);
			set_pwd(new_path, this);
		}
	}
	if (follow_symlinks)
		free(new_path);
}
