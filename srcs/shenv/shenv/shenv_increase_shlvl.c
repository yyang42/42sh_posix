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
#include "twl_arr.h"
#include "xopt.h"
#include "twl_stdlib.h"

void				shenv_increase_shlvl(t_shenv *this)
{
	t_shvar			*shvar;
	char			*shlvl;

	shvar = shenv_shvars_get(this, "SHLVL");
	if (shvar)
	{
		if (twl_str_is_pos_num(shvar->shvar_value))
		{
			shlvl = twl_itoa(twl_atoi(shvar->shvar_value) + 1);
			shenv_shvars_set(this, shvar->shvar_key, shlvl, this->shenv_name);
			free(shlvl);
		}
	}
	else
	{
		shvar = shenv_shvars_set(this, "SHLVL", "1", this->shenv_name);
	}
	if (shvar)
	{
		shvar->shvar_exported = true;
	}
}
