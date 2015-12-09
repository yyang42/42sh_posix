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

#include "env.h"
#include "twl_stdio.h"
#include <stdio.h>

int		check_invalid(t_opt *opt)
{
	char				*invalid;

	invalid = twl_opt_check_invalid_opts(opt);
	if (invalid && twl_strlen(invalid) > 0)
	{
		twl_dprintf(2, "env: illegal option -- %s\n%s", invalid,
			"usage: env [-i] [name=value ...] [utility [argument ...]]\n");
		return (0);
	}
	return (1);
}