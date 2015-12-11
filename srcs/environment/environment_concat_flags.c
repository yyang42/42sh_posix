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

#include "xopt.h"
#include "environment.h"
#include "twl_string.h"
#include "twl_lst.h"
#include "twl_opt_elem.h"

static void			concat_flag(void *data, void *context)
{
	t_opt_elem	*elem;
	char		**concat_ptr;
	char		*concat;

	elem = data;
	concat_ptr = context;
	concat = *concat_ptr;
	if (elem && elem->key)
	{
		concat = twl_strjoinfree(concat, elem->key, 'l');
		*concat_ptr = concat;
	}
}

char				*environment_concat_flags(t_environment *env)
{
	char	*concat;

	concat = twl_strdup("");
	if (env && env->flags)
		twl_lst_iter(env->flags, concat_flag, &concat);
	return concat;
}
