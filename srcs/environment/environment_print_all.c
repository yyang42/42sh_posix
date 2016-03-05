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

static bool		cmp_vars(void *item1, void *item2, void *context)
{
	t_envvar	*var1;
	t_envvar	*var2;

	var1 = item1;
	var2 = item2;
	(void)context;
	return (twl_strcmp(var1->envvar_key, var2->envvar_key) <= 0);
}

static void		print_envvar(void *data)
{
	t_envvar	*var;

	var = data;
	twl_printf("%s=%s\n", var->envvar_key, var->envvar_value);
}



void			environment_print_all(t_shenv *this)
{
	twl_lst_sort(this->envvars, cmp_vars, NULL);
	twl_lst_iter0(this->envvars, print_envvar);
}
