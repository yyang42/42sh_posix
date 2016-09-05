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

#include "shenv/shenv.h"
#include "builtin/cmds/builtin_cd.h"

static void		shenv_set_current_directory2(t_shenv *this, char **cwd,
	char *shvar_pwd, char **phypath_pwd)
{
	if (!shvar_pwd || !twl_strcmp(shvar_pwd, *cwd))
		this->shenv_current_directory = *cwd;
	else if (shvar_pwd)
	{
		*phypath_pwd = builtin_cd_phypath(shvar_pwd);
		if (*phypath_pwd && !twl_strcmp(*cwd, *phypath_pwd))
		{
			this->shenv_current_directory = twl_strdup(shvar_pwd);
			free(*cwd);
		}
		else
			this->shenv_current_directory = *cwd;
		if (*phypath_pwd)
			free(*phypath_pwd);
	}
}

void			shenv_set_current_directory(t_shenv *this, char *from_whom)
{
	char		*cwd;
	char		*shvar_pwd;
	char		*phypath_pwd;

	cwd = getcwd(NULL, 0);
	shvar_pwd = shenv_shvars_get_value(this, "PWD");
	if (cwd == NULL)
	{
		twl_dprintf(2, "%s: error retrieving current directory: getcwd: %s\n",
				from_whom, strerror(errno));
		this->shenv_current_directory = NULL;
	}
	else
	{
		shenv_set_current_directory2(this, &cwd, shvar_pwd, &phypath_pwd);
	}
}
