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

#include "shenv/shenv.h"

static bool		cmp_vars(void *item1, void *item2, void *context)
{
	t_shvar	*var1;
	t_shvar	*var2;

	var1 = item1;
	var2 = item2;
	(void)context;
	return (twl_strcmp(var1->shvar_key, var2->shvar_key) <= 0);
}

static void		print_shvar(void *data)
{
	t_shvar	*var;

	var = data;
	twl_printf("%s=%s\n", var->shvar_key, var->shvar_value);
}



void			environment_print_all(t_shenv *this)
{
	twl_lst_sort(this->shvars, cmp_vars, NULL);
	twl_lst_iter0(this->shvars, print_shvar);
}
