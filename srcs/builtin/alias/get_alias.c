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

#include "builtin/alias.h"

char			*get_alias(char *key, t_environment *this)
{
	char			*value;

	value = twl_dict_get(this->alias, key);
	if (!value)
	{
		environment_set_last_exit_status_2(this, BUILTIN_EXEC_FAILURE);
	}
	return (value);
}
