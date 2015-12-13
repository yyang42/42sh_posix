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

static void			concat_pos_param(void *data, void *context, void *sep_)
{
	char		*elem;
	char		**concat_ptr;
	char		*concat;
	char		*sep;

	elem = data;
	sep = sep_;
	concat_ptr = context;
	concat = *concat_ptr;
	if (elem)
	{
		if (twl_strcmp(concat, "") != 0)
			concat = twl_strjoinfree(concat, sep, 'l');
		concat = twl_strjoinfree(concat, elem, 'l');
		*concat_ptr = concat;
	}
}

char				*environment_concat_pos_param_char(t_environment *env,
																	char *sep)
{
	char	*concat;

	concat = twl_strdup("");
	if (env && env->pos_params)
		twl_lst_iter2(env->pos_params, concat_pos_param, &concat, sep);
	return (concat);
}
