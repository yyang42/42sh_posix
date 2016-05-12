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
#include <pwd.h>
#include <errno.h>

char				*shenv_get_home(t_shenv *this)
{
	char			*home;
	struct passwd	*pw;

	home = shenv_shvars_get_value(this, "HOME");
	if (!home)
	{
		free(this->shenv_home_pw_dir);
		if ((pw = getpwuid(geteuid())))
		{
			this->shenv_home_pw_dir = twl_strdup(pw->pw_dir);
			home = this->shenv_home_pw_dir;
		}
	}
	return (home);
}
