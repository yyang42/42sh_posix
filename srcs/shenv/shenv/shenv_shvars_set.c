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

t_shvar				*shenv_shvars_set(t_shenv *shenv, char *key, char *value, char *command_name)
{
	t_shvar			*shvar;

	if (!token_utils_is_valid_name(key))
	{
		shenv_print_error_printf(shenv_singleton(),
			shenv_get_cur_line(),
			command_name, "`%s': %s", key, "not a valid identifier");
		shenv->last_exit_code = EXIT_FAILURE;
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
