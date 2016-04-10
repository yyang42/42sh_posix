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
#include "file.h"

char				*shenv_find_binary_path(t_shenv *env, char *cmd)
{
	char			*path;

	path = twl_htab_get(env->shenv_binary_db, cmd);
	if (!path)
		shenv_build_binary_db(env);
	path = twl_htab_get(env->shenv_binary_db, cmd);
	return (path);
}
