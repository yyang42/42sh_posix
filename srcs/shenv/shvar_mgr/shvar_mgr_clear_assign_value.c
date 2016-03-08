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

#include "shenv/shvar_mgr.h"

static void			iter_clean_assign(void *data)
{
	t_shvar			*shvar;

	shvar = data;
	if (shvar->shvar_assign_value)
		free(shvar->shvar_assign_value);
	shvar->shvar_assign_value = NULL;
}

void				shvar_mgr_clear_assign_value(t_lst *shvars)
{
	twl_lst_iter0(shvars, iter_clean_assign);
}
