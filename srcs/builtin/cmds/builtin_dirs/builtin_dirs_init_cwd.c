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

#include "builtin/cmds/builtin_dirs.h"

bool			builtin_dirs_init_cwd(char *cmd)
{
	t_lst		*dirs;
	char		*cwd;

	dirs = builtin_dirs_singleton();
	cwd = shenv_get_current_directory(shenv_singleton(), cmd);
	if (!cwd)
	{
		return (false);
	}
	twl_lst_push_front(dirs, twl_strdup(cwd));
	return (true);
}
//
//bool			builtin_dirs_init_cwd(char *cmd)
//{
//	t_lst		*dirs;
//	char		*cwd;
//
//	dirs = builtin_dirs_singleton();
//	cwd = NULL;
//	cwd = getcwd(NULL, 4096);
//	if (cwd == NULL)
//	{
//		shenv_singl_error(1, "%s: getcwd: %s", cmd, strerror(errno));
//		return (false);
//	}
//	twl_lst_push_front(dirs, cwd);
//	return (true);
//}
