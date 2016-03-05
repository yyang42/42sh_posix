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
	t_environment_var	*var1;
	t_environment_var	*var2;

	var1 = item1;
	var2 = item2;
	(void)context;
	return (twl_strcmp(var1->evar_key, var2->evar_key) <= 0);
}

static void		print_env_var(void *data)
{
	t_environment_var	*var;

	var = data;
	twl_printf("%s=%s\n", var->evar_key, var->evar_value);
}



void			environment_print_all(t_environment *this)
{
	twl_lst_sort(this->env_vars, cmp_vars, NULL);
	twl_lst_iter0(this->env_vars, print_env_var);
}
