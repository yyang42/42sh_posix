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
#include "twl_dict.h"

void				xopt_init(t_xopt *xopt, char **av)
{
	xopt->opt__ = twl_opt_new(av, XOPT_VALID_OPTS);
	xopt_check_valid_opts(xopt);
	xopt->print_ast = twl_opt_exist(xopt->opt__, "z");
}
