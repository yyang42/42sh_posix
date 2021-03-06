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

void			builtin_dirs_print_home(void *dir, t_shenv *shenv)
{
	char		*home;

	if (!(home = shenv_shvars_get_value(shenv, "HOME")))
	{
		twl_putstr(dir);
		return ;
	}
	if (home[0] == '/' && home[1] == '\0')
	{
		twl_putstr(dir);
		return ;
	}
	if (!twl_strncmp(home, dir, twl_strlen(home)))
	{
		twl_putstr("~");
		twl_putstr(dir + twl_strlen(home));
	}
	else
		twl_putstr(dir);
}
