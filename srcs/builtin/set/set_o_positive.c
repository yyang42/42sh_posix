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

	xopt = context;
	flag = data;
	if (twl_opt_exist(xopt->opt__, key))
		twl_printf("set -o %s\n", flag);
	else
		twl_printf("set +o %s\n", flag);
}


void				set_o_positive()
{
	t_xopt		*xopt;

	xopt = xopt_singleton();
	if (xopt->flag_verbose)
		twl_dict_iter(xopt->flag_verbose, get_flag_verbose, xopt);
}
