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
#include "twl_opt.h"
#include "twl_opt_elem.h"
#include "twl_xstring.h"

void				set_add_flag(char *flag)
{
	t_xopt		*xopt;

	xopt = xopt_singleton();
	if (xopt && xopt->opt__ && !twl_opt_exist(xopt->opt__, flag))
	{
		twl_lst_push(xopt->opt__->opts, twl_opt_elem_new(flag, NULL));
	}

}
