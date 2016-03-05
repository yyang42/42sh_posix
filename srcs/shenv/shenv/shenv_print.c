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
	t_shvar	*var;

	var = data;
	if (var->shvar_type == ENVIRONMENT)
		twl_printf("%s=%s\n", var->shvar_key, var->shvar_value ? var->shvar_value : "");
}

void			shenv_print(t_shenv *this)
{
	twl_lst_iter0(this->shvars, print_shvar);
}
