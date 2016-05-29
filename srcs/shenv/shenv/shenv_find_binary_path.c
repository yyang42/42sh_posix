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
#include "file.h"

static void			update_binary_db_on_path_change(t_shenv *env)
{
	char			*path_var;

	path_var = shenv_shvars_get_value(env, "PATH");
	if (path_var)
	{
		if (!twl_strequ(env->shenv_binary_saved_path, path_var))
		{
			shenv_build_binary_db(env);
			shenv_set_binary_saved_path(env, path_var);
		}
	}
}

static bool			is_absolute_or_relative_path(char *cmd)
{
	if (!cmd)
		return (false);
	return (
		   (cmd[0] == '/')
		|| (twl_strncmp(cmd, "./", 2) == 0)
		|| (twl_strncmp(cmd, "../", 3) == 0)
	);
}

char				*shenv_find_binary_path(t_shenv *env, char *cmd)
{
	char			*path;

	update_binary_db_on_path_change(env);
	if (is_absolute_or_relative_path(cmd))
		return (file_exists(cmd) ? cmd : NULL);
	path = NULL;
	if (env->shenv_binary_db)
		path = twl_htab_get(env->shenv_binary_db, cmd);
	if (!path)
		shenv_build_binary_db(env);
	path = twl_htab_get(env->shenv_binary_db, cmd);
	return (path);
}
