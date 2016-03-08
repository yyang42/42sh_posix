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

static void		print_shvar(void *data)
{
	t_shvar			*var;
	char			*value;

	var = data;
	value = NULL;
	if (var->shvar_assign_value)
		value = var->shvar_assign_value;
	else if (var->shvar_exported)
		value = var->shvar_value;
	if (value)
		twl_printf("%s=%s\n", var->shvar_key, value);
}

void			shenv_print(t_shenv *this)
{
	twl_lst_iter0(this->shvars, print_shvar);
}
