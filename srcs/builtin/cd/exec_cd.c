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

#include "cd.h"

static void	set_oldpwd(t_environment *env)
{
	char			*oldpwd;

	oldpwd = environment_getenv_value(env, "PWD");
	if (oldpwd != NULL)
	{
		environment_setenv_value(env, "OLDPWD", oldpwd);
	}
}

static void	set_pwd(char *pwd, t_environment *env)
{
	environment_setenv_value(env, "PWD", pwd);
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
	struct stat		sb;
	char			*new_path;

	new_path = NULL;
	if (!no_symlinks)
		new_path = set_canonical_form(path);
	if (!lstat(path, &sb) || no_symlinks)
	{
		if (S_ISLNK(sb.st_mode) || no_symlinks)
			cd_symlink(no_symlinks ? path : new_path, this);
		else if (S_ISDIR(sb.st_mode) && sb.st_mode & 0111)
		{
			set_oldpwd(this);
			if (chdir(no_symlinks ? path : new_path) == 0)
				set_pwd(no_symlinks ? path : new_path, this);
		}
		else if (!S_ISDIR(sb.st_mode))
			twl_dprintf(2, "cd: %s: Not a directory\n", path);
		else if (S_ISDIR(sb.st_mode) && !(sb.st_mode & 0111))
			twl_dprintf(2, "cd: %s: Permission denied\n", path);
	}
	else
		twl_dprintf(2, "cd: %s: No such file or directory\n", path);
	if (!no_symlinks)
		free(new_path);
}
