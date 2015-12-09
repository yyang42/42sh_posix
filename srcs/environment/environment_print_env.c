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

static void		print_env_var(void *data)
{
	t_environment_var	*var;

	var = data;
	if (var->type == ENVIRONMENT)
		twl_printf("%s=%s\n", var->key, var->value);
}

void			environment_print_env(t_environment *this)
{
	twl_lst_iter0(this->env_vars, print_env_var);
}
