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

#include "environment.h"

static void		print_envvar(void *data)
{
	t_envvar	*var;

	var = data;
	if (var->envvar_type == ENVIRONMENT)
		twl_printf("%s=%s\n", var->envvar_key, var->envvar_value);
}

void			environment_print(t_shenv *this)
{
	twl_lst_iter0(this->envvars, print_envvar);
}
