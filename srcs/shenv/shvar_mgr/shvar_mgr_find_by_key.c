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

static bool			find_fn(void *shvar_, void *key)
{
	t_shvar	*shvar;

	shvar = shvar_;
	return (twl_strequ(shvar->shvar_key, key));
}

t_shvar				*shvar_mgr_find_by_key(t_lst *shvars, char *key)
{
	return (twl_lst_find(shvars, find_fn, key));
}
