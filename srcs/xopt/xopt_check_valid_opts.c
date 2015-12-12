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

void				xopt_check_valid_opts(t_xopt *xopt)
{
	char			*first_not_valid_opt;

	first_not_valid_opt = twl_opt_check_invalid_opts(xopt->opt);
	if (first_not_valid_opt)
	{
		twl_xprintf("Invalid Option: %s\n", first_not_valid_opt);
	}
}
