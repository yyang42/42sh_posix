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

t_shvar				*shenv_shvars_set_int(t_shenv *shenv,
					char *key, int intval, char *command_name)
{
	t_shvar			*shvar;
	char			*value;

	value = twl_itoa(intval);
	shvar = shenv_shvars_set(shenv, key, value, command_name);
	free(value);
	return (shvar);
}
