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
#include "twl_string.h"
#include "twl_lst.h"
#include "twl_opt_elem.h"

static void			concat_opt(void *data, void *context)
{
	t_opt_elem	*elem;
	char		**concat_ptr;
	char		*concat;

	elem = data;
	concat_ptr = context;
	concat = *concat_ptr;
	if (elem && elem->key)
	{
		concat = twl_strjoin(concat, elem->key);
		*concat_ptr = concat;
	}
}

char				*xopt_concat_opts(t_xopt *xopt)
{
	char	*concat;

	concat = twl_strdup("");
	if (xopt && xopt->opt__)
		twl_lst_iter(xopt->opt__->opts, concat_opt, &concat);
	return (concat);
}
