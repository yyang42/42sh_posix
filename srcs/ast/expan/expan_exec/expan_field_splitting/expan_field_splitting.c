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
#include "ast/expan/ast_expan_field_splitting.h"
#include "environment.h"
#include "patmatch.h"
#include "twl_xstring.h"

void		expan_field_splitting(char **res)
{
	t_environment		*env;
	t_environment_var	*ifs;

	env = environment_singleton();
	ifs = environment_get(env, "IFS");
	if (ifs && ifs->value_is_set == 1)
	{
		if (!twl_strcmp(ifs->value, " ") || !twl_strcmp(ifs->value, "\t")
			|| !twl_strcmp(ifs->value, "\n"))
			expan_field_splitting_white_spaces(res);
		else
			expan_field_splitting_ifs(res, ifs->value);
	}
	else if (!ifs)
	{
		expan_field_splitting_white_spaces(res);
	}
}
