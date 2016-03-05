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

#include "builtin/builtin_mgr.h"

static bool			find_fn(void *builtin_, void *name)
{
	t_builtin	*builtin;

	builtin = builtin_;
	return (twl_strequ(builtin->builtin_name, name));
}

t_builtin			*builtin_mgr_find_by_name(t_lst *builtins, char *name)
{
	return (twl_lst_find(builtins, find_fn, name));
}
