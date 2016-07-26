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

#include "expan/expansion.h"
#include "shenv/shenv.h"

void			expansion_prompt_current_basename(t_expansion *this)
{
	char		*home;
	char		*cwd;
	char		*basename;

	home = shenv_shvars_get_value(shenv_singleton(), "HOME");
	cwd = shenv_singleton()->shenv_current_directory;
	if (!cwd)
	{
		expansion_push_before_split(this, "(null)", false);
	}
	else if (!home || twl_strcmp(home, cwd))
	{
		basename = twl_strrchr(cwd, '/');
		if (basename == cwd)
			;
		else if (basename == cwd + 1)
			basename -= 1;
		else
			basename += 1;
		expansion_push_before_split(this, basename, false);
	}
	else
	{
		expansion_push_before_split(this, "~", false);
	}
}
