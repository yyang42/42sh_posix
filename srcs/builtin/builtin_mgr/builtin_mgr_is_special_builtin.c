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

bool				builtin_mgr_is_special_builtin(t_lst *builtins, char *name)
{
	t_builtin		*builtin;

	if (!name)
	{
		LOG_ERROR("name not set");
		return (false);
	}
	builtin = builtin_mgr_find_by_name(builtins, name);
	if (!builtin)
		return (false);
	return (builtin->builtin_flags & BUILTIN_FLAG_SPECIAL_BUILTIN);
}
