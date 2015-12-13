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
#include "twl_opt_elem.h"

static void			print_opt(void *data)
{
	t_opt_elem *elem;

	elem = data;
	if (elem && elem->key)
		twl_printf("%s\n", elem->key);
}

void				xopt_print_opts(t_xopt *xopt)
{
	if (xopt && xopt->opt)
		twl_lst_iter0(xopt->opt->opts, print_opt);
}
