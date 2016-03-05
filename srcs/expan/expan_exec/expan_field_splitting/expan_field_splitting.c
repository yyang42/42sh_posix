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

#include "basics.h"
#include "expan/expan_field_splitting.h"
#include "shenv/shenv.h"
#include "pattern_matching/patmatch.h"
#include "twl_xstring.h"

void		expan_field_splitting(char **res)
{
	t_shenv		*env;
	t_shvar	*ifs;

	env = shenv_singleton();
	ifs = shenv_get(env, "IFS");
	if (ifs && ifs->shvar_value_is_set == 1)
	{
		if (!twl_strcmp(ifs->shvar_value, " ") || !twl_strcmp(ifs->shvar_value, "\t")
			|| !twl_strcmp(ifs->shvar_value, "\n"))
			expan_field_splitting_white_spaces(res);
		else
			expan_field_splitting_ifs(res, ifs->shvar_value);
	}
	else if (!ifs)
	{
		expan_field_splitting_white_spaces(res);
	}
}
