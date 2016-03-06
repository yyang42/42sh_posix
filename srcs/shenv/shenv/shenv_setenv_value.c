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

#include "builtin/builtin.h"
#include "token/token_utils.h"

#include "shenv/shenv.h"

t_shvar				*shenv_setenv_value(t_shenv *shenv, char *key, char *value, char *command_name)
{
	t_shvar			*shvar;

	if (!token_utils_is_valid_name(key))
	{
		twl_dprintf(2, "%s: `%s': not a valid identifier\n", command_name ? command_name : "42sh", key);
		shenv_set_last_exit_status(shenv, BUILTIN_EXEC_FAILURE);
		return (NULL);
	}
	shvar = shvar_mgr_find_or_create(shenv->shvars, key);
	shvar->shvar_exported = true;
	if (value)
	{
		shvar_set_value(shvar, value);
	}
	return (shvar);
}
