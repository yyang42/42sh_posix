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

#include "builtin/cmds/builtin_pwd.h"

void			builtin_pwd_exec_logical(void)
{
//	struct stat	logic;
//	struct stat	physic;
//	char		*pwd;
//
//	/*
//	 * Check that $PWD is an absolute logical pathname referring to
//	 * the current working directory.
//	 */
//	pwd = shenv_shvars_get(shenv_singleton(), "PWD");
//	if ((pwd = getenv("PWD")) != NULL && *pwd == '/') {
//		if (stat(pwd, &lg) == -1 || stat(".", &phy) == -1)
//			return (NULL);
//		if (lg.st_dev == phy.st_dev && lg.st_ino == phy.st_ino)
//			return (pwd);
//	}
//
//	errno = ENOENT;
//	return (NULL);
}
