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

#include "builtin/builtin_cd.h"

static void	set_oldpwd(t_environment *env)
{
	char			*oldpwd;

	oldpwd = environment_getenv_value(env, "PWD");
	if (oldpwd != NULL)
	{
		environment_setenv_value(env, "OLDPWD", oldpwd, 1);
	}
}

static void	set_pwd(char *pwd, t_environment *env)
{
	environment_setenv_value(env, "PWD", pwd, 1);
}

static void	cd_symlink(char *path, t_environment *this)
{
	char buf[PATH_MAX];

	if (chdir(path) == 0)
	{
		set_oldpwd(this);
		getcwd(buf, PATH_MAX);
		set_pwd(buf, this);
	}
}

void		execute_cd(char *path, int no_symlinks, t_environment *this)
{
	char			*new_path;

	new_path = NULL;
	if (!no_symlinks)
		new_path = set_canonical_form(path);
	if (no_symlinks)
		cd_symlink(path, this);
	else
	{
		if (chdir(new_path) == 0)
		{
			set_oldpwd(this);
			set_pwd(new_path, this);
		}
		else
			perror("cd");
	}
	if (!no_symlinks)
		free(new_path);
}
