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

#include "set.h"
#include "xopt.h"
#include "twl_opt.h"
#include "twl_opt_elem.h"
#include "twl_xstring.h"

static void			get_flag_verbose(char *key, void *data, void *context)
{
	t_xopt		*xopt;
	char		*flag;
	int			space_count;
	char		*space;

	xopt = context;
	flag = data;
	space_count = 16 - (int)twl_strlen(flag);
	if (space_count < 0)
		space = twl_strdup("\t");
	else
	{
		space = (char*)malloc(sizeof(char) * (space_count + 1));
		twl_memset(space, ' ', space_count);
		space[space_count] = 0;
	}
	if (twl_opt_exist(xopt->opt__, key))
		twl_printf("%s%s%s\n", flag, space, "on");
	else
		twl_printf("%s%s%s\n", flag, space, "off");
	free(space);
}


void				set_o_negative()
{
	t_xopt		*xopt;

	xopt = xopt_singleton();
	if (xopt->flag_verbose)
		twl_dict_iter(xopt->flag_verbose, get_flag_verbose, xopt);
}
